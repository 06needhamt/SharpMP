﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SharpMP
{
    public unsafe struct NestLock
    {
        void* _lk;
    }
}
