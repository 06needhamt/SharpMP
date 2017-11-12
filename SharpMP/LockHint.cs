using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SharpMP
{
    public enum LockHint : int
    {
        None = 0,
        Uncontended = 1,
        Contended = (1 << 1),
        Nonspeculative = (1 << 2),
        Speculative = (1 << 3),
        K_HLE = (1 << 16),
        K_RTM = (1 << 17),
        K_Adaptive = (1 << 18)
    }
}
