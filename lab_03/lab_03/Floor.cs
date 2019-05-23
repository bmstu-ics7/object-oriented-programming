using System;
namespace lab_03
{
    public class Floor
    {
        private enum State
        {
            Wait,   // Ожидание
            NoWait  // Нет ожидания
        }

        public Floor()
        {
            Number = 1;
            FloorState = State.NoWait;

            EventWait += SetWait;
            EventCome += ComeToFloor;
        }

        public Floor(int number)
        {
            Number = number;
            FloorState = State.NoWait;

            EventWait += SetWait;
            EventCome += ComeToFloor;
        }

        public delegate void Event();
        public event Event EventWait;
        public event Event EventCome;

        public void CallEventWait()
        {
            EventWait?.Invoke();
        }

        public void CallEventCome()
        {
            EventCome?.Invoke();
        }

        private int number;

        public int Number 
        {
            get => number;
            private set => number = value;
        }

        private State FloorState;

        public bool GetState
        {
            get => FloorState == State.Wait;
        }

        public void SetWait()
        {
            FloorState = State.Wait;
        }

        public void ComeToFloor()
        {
            FloorState = State.NoWait;
        }
    }
}
