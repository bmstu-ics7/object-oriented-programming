using System;
using System.Collections.Generic;
using System.Threading;

namespace lab_03
{
    public class Elevator
    {
        private enum state
        {
            GoUp,               // Подъем
            GoDown,             // Спуск
            WaitWithOpenDoors,  // Ожидание с открытыми дверьми
            Wait                // Ожидание с закрытими дверьми
        }

        public Elevator()
        {
            ElevatorState = state.Wait;

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

            doors = new Doors();

            CurrentFloor = 0;

            go = 0;

            EventGoUp += GoUp;
            EventGoDown += GoDown;
            EventWaitWithOpenDoors += WaitWithOpenDoors;
            EventWait += Wait;

            EventWait?.Invoke();
        }

        public delegate void Event();
        public event Event EventGoUp;
        public event Event EventGoDown;
        public event Event EventWaitWithOpenDoors;
        public event Event EventWait;

        private state ElevatorState;

        public string State
        {
            get
            {
                switch (ElevatorState)
                {
                    case state.GoUp:
                        return "Вверх";
                    case state.GoDown:
                        return "Вниз";
                    case state.WaitWithOpenDoors:
                        return "Открытые двери";
                    case state.Wait:
                        return "Ожидание";
                    default:
                        return "Неизвестное состояние";
                }
            }
        }

        public Doors GetDoors
        {
            get => doors;
        }

        private List<Floor> WaitFloors;
        public void SetWaitFloor(int i)
        {
            WaitFloors[i - 1].SetWait();

            if (ElevatorState == state.Wait)
            {
                EventWait?.Invoke();
            }
        }

        private List<Floor> ComeToFloors;
        public void SetComeFloor(int i)
        {
            ComeToFloors[i - 1].SetWait();

            if (ElevatorState == state.Wait)
            {
                EventWait?.Invoke();
            }
        }

        public List<Floor> GetWaitFloors
        {
            get => WaitFloors;
        }

        public List<Floor> GetComeToFloors
        {
            get => ComeToFloors;
        }

        private Doors doors;

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

        public void GoUp()
        {
            go = 1;
            ElevatorState = state.GoUp;
            doors.CallEventClosing();
            Thread.Sleep(500);
            CurrentFloor++;

            if (ComeToFloors[CurrentFloor].State ||
                WaitFloors[CurrentFloor].State)
            {
                EventWaitWithOpenDoors?.Invoke();
            }
            else
            {
                EventGoUp?.Invoke();
            }
        }

        public void GoDown()
        {
            go = -1;
            ElevatorState = state.GoDown;
            doors.CallEventClosing();
            Thread.Sleep(500);
            CurrentFloor--;

            if (ComeToFloors[CurrentFloor].State ||
                WaitFloors[CurrentFloor].State)
            {
                EventWaitWithOpenDoors?.Invoke();
            }
            else
            {
                EventGoDown?.Invoke();
            }
        }

        public void WaitWithOpenDoors()
        {
            ElevatorState = state.WaitWithOpenDoors;
            doors.CallEventOpening();

            ComeToFloors[CurrentFloor].ComeToFloor();
            WaitFloors[CurrentFloor].ComeToFloor();

            Thread.Sleep(1000);
            EventWait?.Invoke();
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
                if (ComeToFloors[i].State)
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
                    if (WaitFloors[i].State)
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

        public void Wait()
        {
            ElevatorState = state.Wait;
            doors.CallEventClosing();
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
                    EventWaitWithOpenDoors?.Invoke();
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
    }
}
