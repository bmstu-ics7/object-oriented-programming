using System;
using System.Threading;
using System.Threading.Tasks;

namespace lab_03
{
    public class Doors
    {
        private enum state
        {
            Open,       // Открыты
            Opening,    // Открытие
            Close,      // Закрыты
            Closing     // Закрытие
        }

        public Doors()
        {
            DoorsState = state.Close;
            EventOpening += Opening;
            EventClosing += Closing;
        }

        public delegate void Event();
        public event Event EventOpening;
        public event Event EventClosing;

        public void CallEventOpening()
        {
            EventOpening?.Invoke();
        }

        public void CallEventClosing()
        {
            EventClosing?.Invoke();
        }

        private state DoorsState;

        public string State
        {
            get
            {
                switch (DoorsState)
                {
                    case state.Close:
                        return "Закрыты";
                    case state.Closing:
                        return "Закрываются";
                    case state.Open:
                        return "Открыты";
                    case state.Opening:
                        return "Открываются";
                    default:
                        return "Неизвестное состояние";
                }
            }
        }

        public bool IsOpen
        {
            get => DoorsState == state.Open;
        }

        public void Open()
        {
            DoorsState = state.Open;
        }

        public void Close()
        {
            DoorsState = state.Close;
        }

        public void Opening()
        {
            if (!IsOpen)
            {
                DoorsState = state.Opening;
                Thread.Sleep(2000);
                Open();
            }
        }

        public void Closing()
        {
            if (IsOpen)
            {
                DoorsState = state.Closing;
                Thread.Sleep(2000);
                Close();
            }
        }
    }
}
