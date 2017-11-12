using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SharpMP
{
    public enum ScheduleKind : int
    {
        Static = 1,
        Dynamic = 2,
        Guided = 3,
        Auto = 4
    }
}
