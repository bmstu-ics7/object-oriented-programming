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
            Change = false;

            EventOpen += Open;
            EventOpening += Opening;
            EventClose += Close;
            EventClosing += Closing;
        }

        private delegate void Event();
        private event Event EventOpen;
        private event Event EventOpening;
        private event Event EventClose;
        private event Event EventClosing;

        public void Run()
        {
            if (!IsOpen)
            {
                EventClose?.Invoke();
            }
            else
            {
                EventOpen?.Invoke();
            }
        }

        private bool Change;

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

        private void Open()
        {
            if (Change)
            {
                DoorsState = state.Closing;
                Change = false;
                EventClosing?.Invoke();
            }
        }

        private void Opening()
        {
            Thread.Sleep(1000);
            DoorsState = state.Open;
            EventOpen?.Invoke();
        }

        private void Close()
        {
            if (Change)
            {
                DoorsState = state.Opening;
                Change = false;
                EventOpening?.Invoke();
            }
        }

        private void Closing()
        {
            Thread.Sleep(1000);
            DoorsState = state.Close;
            EventClose?.Invoke();
        }

        public void MakeChange()
        {
            Change = true;
            Thread.Sleep(1000);
        }
    }
}
