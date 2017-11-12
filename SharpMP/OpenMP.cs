using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace SharpMP
{
    public static unsafe class OpenMP
    {
        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern void SetDynamic(int dynamic);

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern void SetNested(int nested);

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern void SetMaxActiveLevels(int maxLevels);

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern void SetSchedule(ScheduleKind schedule, int chunkSize);

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int GetNumThreads();

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int GetDynamic();

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int GetNested();

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int GetMaxThreads();

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int GetThreadNum();

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int GetNumProcs();

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int InParralel();

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int IsFinal();

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int GetActiveLevel();

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int GetLevel();

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int GetAncestorThreadNum(int threadNum);

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int GetTeamSize(int team);

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int GetThreadLimit();

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int GetMaxActiveLevels();

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern void GetSchedule(void* kind, int* chunksize);

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int GetMaxTaskPriority();

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern void InitLock(Lock* @lock);

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern void SetLock(Lock* @lock);

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern void UnsetLock(Lock* @lock);

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern void DestroyLock(Lock* @lock);

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int TestLock(Lock* @lock);

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern void InitNestLock(NestLock* @lock);

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern void SetNestLock(NestLock* @lock);

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern void UnsetNestLock(NestLock* @lock);

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern void DestroyNestLock(Lock* @lock);

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int TestNestLock(NestLock* @lock);

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern void InitNestLockWithHint(NestLock* @lock, LockHint hint);

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern void InitLockWithHint(Lock* @lock, LockHint hint);

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern double GetWTime();

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern double GetWTick();

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int GetDefaultDevice();

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern void SetDefaultDevice(int device);

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int isInitialDevice();

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int GetNumDevices();

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int GetNumTeams();

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int GetTeamNum();

        [DllImport("SharpMP-Natives.dll")]
        public static unsafe extern int GetCancellation();
    }
}
