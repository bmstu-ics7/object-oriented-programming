using System;
using System.Threading;
using System.Threading.Tasks;

namespace lab_03
{
    public class Doors
    {
        public const int Wait = 2000;

        private enum State
        {
            Open,       // Открыты
            Opening,    // Открытие
            Close,      // Закрыты
            Closing     // Закрытие
        }

        public Doors()
        {
            DoorsState = State.Close;
            EventOpening += Opening;
            EventClosing += Closing;
        }

        public delegate void Event(Object obj = null);
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

        private State DoorsState;

        public string GetState
        {
            get
            {
                switch (DoorsState)
                {
                    case State.Close:
                        return "Закрыты";
                    case State.Closing:
                        return "Закрываются";
                    case State.Open:
                        return "Открыты";
                    case State.Opening:
                        return "Открываются";
                    default:
                        return "Неизвестное состояние";
                }
            }
        }

        public void Open(Object obj = null)
        {
            DoorsState = State.Open;
        }

        public void Close(Object obj = null)
        {
            DoorsState = State.Close;
        }

        public void Opening(Object obj = null)
        {
            if (DoorsState == State.Close)
            {
                DoorsState = State.Opening;
                TimerCallback call = new TimerCallback(Open);
                Timer timer = new Timer(call, null, Wait, -1);
            }
        }

        public void Closing(Object obj = null)
        {
            if (DoorsState == State.Open)
            {
                DoorsState = State.Closing;
                TimerCallback call = new TimerCallback(Close);
                Timer timer = new Timer(call, null, Wait, -1);
            }
        }
    }
}
