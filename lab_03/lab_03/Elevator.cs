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
            doors.Run();
        }

        delegate void Event();
        private event Event EventGoUp;
        private event Event EventGoDown;
        private event Event EventWaitWithOpenDoors;
        private event Event EventWait;

        private state ElevatorState;

        public void Run()
        {
            EventWait?.Invoke();
        }

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
        }

        private List<Floor> ComeToFloors;
        public void SetComeFloor(int i)
        {
            ComeToFloors[i - 1].SetWait();
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

        private void GoUp()
        {
            go = 1;
            Thread.Sleep(500);
            CurrentFloor++;
            if (ComeToFloors[CurrentFloor].State || 
                WaitFloors[CurrentFloor].State)
            {
                ElevatorState = state.WaitWithOpenDoors;
                ComeToFloors[CurrentFloor].ComeToFloor();
                WaitFloors[CurrentFloor].ComeToFloor();
                EventWaitWithOpenDoors?.Invoke();
                return;
            }
        }

        private void GoDown()
        {
            go = -1;
            Thread.Sleep(500);
            CurrentFloor--;
            if (ComeToFloors[CurrentFloor].State || 
                WaitFloors[CurrentFloor].State)
            {
                ElevatorState = state.WaitWithOpenDoors;
                ComeToFloors[CurrentFloor].ComeToFloor();
                WaitFloors[CurrentFloor].ComeToFloor();
                doors.MakeChange();
                EventWaitWithOpenDoors?.Invoke();
                return;
            }
        }

        private void WaitWithOpenDoors()
        {
            if (currentFloor == 0 || 
                currentFloor == ComeToFloors.Count - 1)
            {
                go = 0;
            }

            doors.MakeChange();
            Thread.Sleep(2000);
            doors.MakeChange();
            ElevatorState = state.Wait;
            EventWait?.Invoke();
        }

        private void Wait()
        {
            int minIndex = -11;
            if (go == 0)
            {
                for (int i = 0; i < ComeToFloors.Count; ++i)
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
                    for (int i = 0; i < WaitFloors.Count; ++i)
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
            }
            else if (go == 1)
            {
                for (int i = currentFloor; i < ComeToFloors.Count; ++i)
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
                    for (int i = currentFloor; i < WaitFloors.Count; ++i)
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

                if (minIndex == -11)
                {
                    go = -1;
                }
            }
            else
            {
                for (int i = ComeToFloors.Count - 1; i > -1; --i)
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
                    for (int i = WaitFloors.Count - 1; i > -1; --i)
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

                if (minIndex == -11)
                {
                    go = 1;
                }
            }

            if (minIndex >= 0)
            {
                if (CurrentFloor == minIndex)
                {
                    ElevatorState = state.WaitWithOpenDoors;
                    return;
                }
                else if (CurrentFloor - minIndex > 0)
                {
                    ElevatorState = state.GoDown;
                    EventGoDown?.Invoke();
                }
                else
                {
                    ElevatorState = state.GoUp;
                    EventGoUp?.Invoke();
                }
            }

            /*if (minIndex == -11)
            {
                EventWait?.Invoke();
            }*/
        }
    }
}
