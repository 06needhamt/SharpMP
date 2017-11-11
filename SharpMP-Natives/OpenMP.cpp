#include <omp.h>
#include "OpenMP.h"
#include "ScheduleKind.h"
#include "Lock.h"
#include "NestLock.h"
#include "LockHint.h"

static_assert(sizeof(int) == 4, "This Library must be compiled in 64-Bit mode");
static_assert(sizeof(void*) == 8, "This Library must be compiled in 64-Bit mode");

extern "C" {
	_declspec(dllexport) void SetNumThreads(int threads) {
		omp_set_num_threads(threads);
	}

	_declspec(dllexport) void SetDynamic(int dynamic) {
		omp_set_dynamic(dynamic);
	}

	_declspec(dllexport) void SetNested(int nested) {
		omp_set_nested(nested);
	}

	_declspec(dllexport) void SetMaxActiveLevels(int maxLevels) {
		omp_set_max_active_levels(maxLevels);
	}

	_declspec(dllexport) void SetSchedule(ScheduleKind schedule, int chunkSize) {
		switch (schedule)
		{
		case ScheduleKind::Static:
			omp_set_schedule(omp_sched_t::omp_sched_static, chunkSize);
			break;
		case ScheduleKind::Dynamic:
			omp_set_schedule(omp_sched_t::omp_sched_dynamic, chunkSize);
			break;
		case ScheduleKind::Guided:
			omp_set_schedule(omp_sched_t::omp_sched_guided, chunkSize);
			break;
		case ScheduleKind::Auto:
			omp_set_schedule(omp_sched_t::omp_sched_auto, chunkSize);
			break;
		default:
			break;
		}
	}

	_declspec(dllexport) int GetNumThreads() {
		return omp_get_num_threads();
	}

	_declspec(dllexport) int GetDynamic() {
		return omp_get_dynamic();
	}

	_declspec(dllexport) int GetNested() {
		return omp_get_nested();
	}

	_declspec(dllexport) int GetMaxThreads() {
		return omp_get_max_threads();
	}

	_declspec(dllexport) int GetThreadNum() {
		return omp_get_thread_num();
	}

	_declspec(dllexport) int GetNumProcs() {
		return omp_get_num_procs();
	}

	_declspec(dllexport) int InParralel() {
		return omp_in_parallel();
	}

	_declspec(dllexport) int InFinal() {
		return omp_in_final();
	}

	_declspec(dllexport) int GetActiveLevel() {
		return omp_get_active_level();
	}

	_declspec(dllexport) int GetLevel() {
		return omp_get_level();
	}

	_declspec(dllexport) int GetAncestorThreadNum(int threadNum) {
		return omp_get_ancestor_thread_num(threadNum);
	}

	_declspec(dllexport) int GetTeamSize(int team) {
		return omp_get_team_size(team);
	}

	_declspec(dllexport) int GetThreadLimit() {
		return omp_get_thread_limit();
	}

	_declspec(dllexport) int GetMaxActiveLevels() {
		return omp_get_max_active_levels();
	}

	_declspec(dllexport) void GetSchedule(void* kind, int* chunkSize) {
		omp_get_schedule(reinterpret_cast<omp_sched_t*>(kind), chunkSize);
	}

	_declspec(dllexport) int GetMaxTaskPriority() {
		return omp_get_max_task_priority();
	}

	_declspec(dllexport) void InitLock(Lock* lock) {
		omp_init_lock(reinterpret_cast<omp_lock_t*>(lock->_lk));
	}

	_declspec(dllexport) void SetLock(Lock* lock) {
		omp_set_lock(reinterpret_cast<omp_lock_t*>(lock->_lk));
	}

	_declspec(dllexport) void UnsetLock(Lock* lock) {
		omp_unset_lock(reinterpret_cast<omp_lock_t*>(lock->_lk));
	}

	_declspec(dllexport) void DestroyLock(Lock* lock) {
		omp_destroy_lock(reinterpret_cast<omp_lock_t*>(lock->_lk));
	}

	_declspec(dllexport) int TestLock(Lock* lock) {
		return omp_test_lock(reinterpret_cast<omp_lock_t*>(lock->_lk));
	}

	_declspec(dllexport) void InitNestLock(NestLock* lock) {
		omp_init_nest_lock(reinterpret_cast<omp_nest_lock_t*>(lock->_lk));
	}

	_declspec(dllexport) void SetNestLock(NestLock* lock) {
		omp_set_nest_lock(reinterpret_cast<omp_nest_lock_t*>(lock->_lk));
	}

	_declspec(dllexport) void UnsetNestLock(NestLock* lock) {
		omp_unset_nest_lock(reinterpret_cast<omp_nest_lock_t*>(lock->_lk));
	}

	_declspec(dllexport) void DestroyNestLock(NestLock* lock) {
		omp_destroy_nest_lock(reinterpret_cast<omp_nest_lock_t*>(lock->_lk));
	}

	_declspec(dllexport) int TestNestLock(NestLock* lock) {
		return omp_test_nest_lock(reinterpret_cast<omp_nest_lock_t*>(lock->_lk));
	}

	_declspec(dllexport) void InitNestLockWithHint(NestLock* lock, LockHint hint) {
		switch (hint)
		{
		case None:
			omp_init_nest_lock_with_hint(reinterpret_cast<omp_nest_lock_t*>(lock->_lk), omp_lock_hint_t::omp_lock_hint_none);
			break;
		case Uncontended:
			omp_init_nest_lock_with_hint(reinterpret_cast<omp_nest_lock_t*>(lock->_lk), omp_lock_hint_t::omp_lock_hint_uncontended);
			break;
		case Contended:
			omp_init_nest_lock_with_hint(reinterpret_cast<omp_nest_lock_t*>(lock->_lk), omp_lock_hint_t::omp_lock_hint_contended);
			break;
		case Nonspeculative:
			omp_init_nest_lock_with_hint(reinterpret_cast<omp_nest_lock_t*>(lock->_lk), omp_lock_hint_t::omp_lock_hint_nonspeculative);
			break;
		case Speculative:
			omp_init_nest_lock_with_hint(reinterpret_cast<omp_nest_lock_t*>(lock->_lk), omp_lock_hint_t::omp_lock_hint_speculative);
			break;
		case K_HLE:
			omp_init_nest_lock_with_hint(reinterpret_cast<omp_nest_lock_t*>(lock->_lk), omp_lock_hint_t::kmp_lock_hint_hle);
			break;
		case K_RTM:
			omp_init_nest_lock_with_hint(reinterpret_cast<omp_nest_lock_t*>(lock->_lk), omp_lock_hint_t::kmp_lock_hint_rtm);
			break;
		case K_Adaptive:
			omp_init_nest_lock_with_hint(reinterpret_cast<omp_nest_lock_t*>(lock->_lk), omp_lock_hint_t::kmp_lock_hint_adaptive);
			break;
		default:
			break;
		}
	}

	_declspec(dllexport) void InitLockWithHint(Lock* lock, LockHint hint) {
		switch (hint)
		{
		case None:
			omp_init_lock_with_hint(reinterpret_cast<omp_lock_t*>(lock->_lk), omp_lock_hint_t::omp_lock_hint_none);
			break;
		case Uncontended:
			omp_init_lock_with_hint(reinterpret_cast<omp_lock_t*>(lock->_lk), omp_lock_hint_t::omp_lock_hint_uncontended);
			break;
		case Contended:
			omp_init_lock_with_hint(reinterpret_cast<omp_lock_t*>(lock->_lk), omp_lock_hint_t::omp_lock_hint_contended);
			break;
		case Nonspeculative:
			omp_init_lock_with_hint(reinterpret_cast<omp_lock_t*>(lock->_lk), omp_lock_hint_t::omp_lock_hint_nonspeculative);
			break;
		case Speculative:
			omp_init_lock_with_hint(reinterpret_cast<omp_lock_t*>(lock->_lk), omp_lock_hint_t::omp_lock_hint_speculative);
			break;
		case K_HLE:
			omp_init_lock_with_hint(reinterpret_cast<omp_lock_t*>(lock->_lk), omp_lock_hint_t::kmp_lock_hint_hle);
			break;
		case K_RTM:
			omp_init_lock_with_hint(reinterpret_cast<omp_lock_t*>(lock->_lk), omp_lock_hint_t::kmp_lock_hint_rtm);
			break;
		case K_Adaptive:
			omp_init_lock_with_hint(reinterpret_cast<omp_lock_t*>(lock->_lk), omp_lock_hint_t::kmp_lock_hint_adaptive);
			break;
		default:
			break;
		}
	}

	_declspec(dllexport) double GetWTime() {
		return omp_get_wtime();
	}

	_declspec(dllexport) double GetWTick() {
		return omp_get_wtick();
	}

	_declspec(dllexport) int GetDefaultDevice() {
		return omp_get_default_device();
	}

	_declspec(dllexport) void SetDefaultDevice(int device) {
		omp_set_default_device(device);
	}

	_declspec(dllexport) int IsInitialDevice() {
		return omp_is_initial_device();
	}

	_declspec(dllexport) int GetNumDevices() {
		return 1; /* omp_get_num_devices();*/ //TODO Support This
	}

	_declspec(dllexport) int GetNumTeams() {
		return omp_get_num_teams();
	}

	_declspec(dllexport) int GetTeamNum() {
		return omp_get_team_num();
	}

	_declspec(dllexport) int GetCancellation() {
		return omp_get_cancellation();
	}
}