using System;
using System.Collections.Generic;
using System.Threading;

namespace lab_03
{
    public class Elevator
    {
        const int WaitGoFloor = 500;
        const int WaitOpen = 1000;

        private enum State
        {
            GoUp,               // Подъем
            GoDown,             // Спуск
            WaitWithOpenDoors,  // Ожидание с открытыми дверьми
            Wait                // Ожидание с закрытими дверьми
        }

        public Elevator()
        {
            ElevatorState = State.Wait;

            WaitFloors = new List<Floor>();
            for (int i = 1; i <= 10; ++i)
            {
                WaitFloors.Add(new Floor(i));
            }

            ComeToFloors = new List<Floor>();
            for (int i = 1; i <= 10; ++i)
            {
                ComeToFloors.Add(new Floor(i));
            }

            Doors = new Doors();

            CurrentFloor = 0;

            go = 0;

            EventGoUp += GoUp;
            EventGoDown += GoDown;
            EventWaitWithOpenDoors += WaitWithOpenDoors;
            EventWait += Wait;
            EventOpen += Open;
            EventClose += Close;

            EventWait?.Invoke();
        }

        public delegate void Event(Object obj = null);
        public event Event EventGoUp;
        public event Event EventGoDown;
        public event Event EventWaitWithOpenDoors;
        public event Event EventWait;
        public event Event EventClose;
        public event Event EventOpen;

        private State ElevatorState;

        public string GetState
        {
            get
            {
                switch (ElevatorState)
                {
                    case State.GoUp:
                        return "Вверх";
                    case State.GoDown:
                        return "Вниз";
                    case State.WaitWithOpenDoors:
                        return "Открытые двери";
                    case State.Wait:
                        return "Ожидание";
                    default:
                        return "Неизвестное состояние";
                }
            }
        }

        public List<Floor> WaitFloors { get; private set; }
        public void SetWaitFloor(int i)
        {
            WaitFloors[i - 1].SetWait();

            if (ElevatorState == State.Wait)
            {
                EventWait?.Invoke();
            }
        }

        public List<Floor> ComeToFloors { get; private set; }
        public void SetComeFloor(int i)
        {
            ComeToFloors[i - 1].SetWait();

            if (ElevatorState == State.Wait)
            {
                EventWait?.Invoke();
            }
        }

        public Doors Doors { get; private set; }

        private int currentFloor;

        public int CurrentFloor
        {
            get => currentFloor;
            private set
            {
                if (value < 0) { currentFloor = 0; }
                else if (value > 9) { currentFloor = 9; }
                else { currentFloor = value; }
            }
        }

        private int go;

        public void GoUp(Object obj = null)
        {
            if (ElevatorState == State.Wait || ElevatorState == State.GoUp)
            {
                go = 1;
                ElevatorState = State.GoUp;
                CurrentFloor++;

                if (ComeToFloors[CurrentFloor].GetState ||
                    WaitFloors[CurrentFloor].GetState)
                {
                    EventOpen?.Invoke();
                }
                else
                {
                    if (EventGoUp != null)
                    {
                        TimerCallback call = new TimerCallback(EventGoUp);
                        Timer timer = new Timer(call, null, WaitGoFloor, -1);
                    }
                }
            }
        }

        public void GoDown(Object obj = null)
        {
            if (ElevatorState == State.Wait || ElevatorState == State.GoDown)
            {
                go = -1;
                ElevatorState = State.GoDown;
                CurrentFloor--;

                if (ComeToFloors[CurrentFloor].GetState ||
                    WaitFloors[CurrentFloor].GetState)
                {
                    EventOpen?.Invoke();
                }
                else
                {
                    if (EventGoDown != null)
                    {
                        TimerCallback call = new TimerCallback(EventGoDown);
                        Timer timer = new Timer(call, null, WaitGoFloor, -1);
                    }
                }
            }
        }

        public void WaitWithOpenDoors(Object obj = null)
        {
            if (ElevatorState == State.GoUp || ElevatorState == State.GoDown)
            {
                ElevatorState = State.WaitWithOpenDoors;

                ComeToFloors[CurrentFloor].ComeToFloor();
                WaitFloors[CurrentFloor].ComeToFloor();

                if (EventClose != null)
                {
                    TimerCallback call = new TimerCallback(EventClose);
                    Timer timer = new Timer(call, null, WaitOpen, -1);
                }
            }
        }

        private int FindFloor()
        {
            int minIndex = -11;
            int startSearch = 0;
            int finishSearch = ComeToFloors.Count;

            if (go == 1)
            {
                startSearch = currentFloor;
            }
            else if (go == -1)
            {
                finishSearch = currentFloor;
            }

            for (int i = startSearch; i < finishSearch; ++i)
            {
                if (ComeToFloors[i].GetState)
                {
                    if (Math.Abs(CurrentFloor - minIndex) >=
                        Math.Abs(CurrentFloor - i))
                    {
                        minIndex = i;
                    }
                }
            }

            if (minIndex == -11)
            {
                for (int i = startSearch; i < finishSearch; ++i)
                {
                    if (WaitFloors[i].GetState)
                    {
                        if (Math.Abs(CurrentFloor - minIndex) >=
                            Math.Abs(CurrentFloor - i))
                        {
                            minIndex = i;
                        }
                    }
                }
            }

            return minIndex;
        }

        public void Wait(Object obj = null)
        {
            ElevatorState = State.Wait;
            int floor = FindFloor();

            if (floor == -11)
            {
                go *= -1;

                floor = FindFloor();
                if (floor == -11)
                {
                    go = 0;
                }
            }

            if (floor != -11)
            {
                if (CurrentFloor == floor)
                {
                    EventOpen?.Invoke();
                }
                else if (CurrentFloor - floor > 0)
                {
                    EventGoDown?.Invoke();
                }
                else
                {
                    EventGoUp?.Invoke();
                }
            }
        }

        public void Open(Object obj = null)
        {
            if (ElevatorState != State.WaitWithOpenDoors)
            {
                Doors.CallEventOpening();

                if (EventWaitWithOpenDoors != null)
                {
                    TimerCallback call = new TimerCallback(EventWaitWithOpenDoors);
                    Timer timer = new Timer(call, null, Doors.Wait, -1);
                }
            }
        }

        public void Close(Object obj = null)
        {
            if (ElevatorState == State.WaitWithOpenDoors)
            {
                Doors.CallEventClosing();

                if (EventWait != null)
                {
                    TimerCallback call = new TimerCallback(EventWait);
                    Timer timer = new Timer(call, null, Doors.Wait, -1);
                }
            }
        }
    }
}
