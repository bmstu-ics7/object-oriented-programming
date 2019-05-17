using System;
namespace lab_03
{
    public class Floor
    {
        private enum state
        {
            Wait,   // Ожидание
            NoWait  // Нет ожидания
        }

        public Floor()
        {
            Number = 1;
            FloorState = state.NoWait;
        }

        public Floor(int number)
        {
            Number = number;
            FloorState = state.NoWait;
        }

        private delegate void Event();

        private int number;

        public int Number 
        {
            get => number;
            private set => number = value;
        }

        private state FloorState;

        public bool State
        {
            get => FloorState == state.Wait;
        }

        public void SetWait()
        {
            FloorState = state.Wait;
        }

        public void ComeToFloor()
        {
            FloorState = state.NoWait;
        }
    }
}
