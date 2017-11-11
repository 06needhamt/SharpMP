#pragma once
#include <omp.h>
#include "ScheduleKind.h"
#include "Lock.h"
#include "NestLock.h"
#include "LockHint.h"

static_assert(sizeof(int) == 4, "This Library must be compiled in 64-Bit mode");
static_assert(sizeof(void*) == 8, "This Library must be compiled in 64-Bit mode");

extern "C" {
	_declspec(dllexport) void SetNumThreads(int threads);
		_declspec(dllexport) void SetDynamic(int dynamic);
		_declspec(dllexport) void SetNested(int nested);
		_declspec(dllexport) void SetMaxActiveLevels(int maxLevels);
		_declspec(dllexport) void SetSchedule(ScheduleKind schedule, int chunkSize);
		_declspec(dllexport) int GetNumThreads();
		_declspec(dllexport) int GetDynamic();
		_declspec(dllexport) int GetNested();
		_declspec(dllexport) int GetMaxThreads();
		_declspec(dllexport) int GetThreadNum();
		_declspec(dllexport) int GetNumProcs();
		_declspec(dllexport) int InParralel();
		_declspec(dllexport) int InFinal();
		_declspec(dllexport) int GetActiveLevel();
		_declspec(dllexport) int GetLevel();
		_declspec(dllexport) int GetAncestorThreadNum(int threadNum);
		_declspec(dllexport) int GetTeamSize(int team);
		_declspec(dllexport) int GetThreadLimit();
		_declspec(dllexport) int GetMaxActiveLevels();
		_declspec(dllexport) void GetSchedule(void* kind, int* chunkSize);
		_declspec(dllexport) int GetMaxTaskPriority();
		_declspec(dllexport) void InitLock(Lock* lock);
		_declspec(dllexport) void SetLock(Lock* lock);
		_declspec(dllexport) void UnsetLock(Lock* lock);
		_declspec(dllexport) void DestroyLock(Lock* lock);
		_declspec(dllexport) int TestLock(Lock* lock);
		_declspec(dllexport) void InitNestLock(NestLock* lock);
		_declspec(dllexport) void SetNestLock(NestLock* lock);
		_declspec(dllexport) void UnsetNestLock(NestLock* lock);
		_declspec(dllexport) void DestroyNestLock(NestLock* lock);
		_declspec(dllexport) int TestNestLock(NestLock* lock);
		_declspec(dllexport) void InitNestLockWithHint(NestLock* lock, LockHint hint);
		_declspec(dllexport) void InitLockWithHint(Lock* lock, LockHint hint);
		_declspec(dllexport) double GetWTime();
		_declspec(dllexport) double GetWTick();
		_declspec(dllexport) int GetDefaultDevice();
		_declspec(dllexport) void SetDefaultDevice(int device);
		_declspec(dllexport) int IsInitialDevice();
		_declspec(dllexport) int GetNumDevices();
		_declspec(dllexport) int GetNumTeams();
		_declspec(dllexport) int GetTeamNum();
		_declspec(dllexport) int GetCancellation();
}