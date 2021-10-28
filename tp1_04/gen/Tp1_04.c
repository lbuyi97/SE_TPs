
#include "Tp1_04.h"
#include "..\inc\sc_types.h"
#include "Tp1_04Required.h"

#include <stdlib.h>
#include <string.h>
/*! \file Implementation of the state machine 'tp1_04'
*/

/* prototypes of all internal functions */
static sc_boolean check_TECX_DEBOUNCE_tr0_tr0(const Tp1_04* handle);
static sc_boolean check_TECX_NO_OPRIMIDO_tr0_tr0(const Tp1_04* handle);
static sc_boolean check_TECX_OPRIMIDO_tr0_tr0(const Tp1_04* handle);
static sc_boolean check_TECX_VALIDACION_tr0_tr0(const Tp1_04* handle);
static sc_boolean check_TECX_VALIDACION_tr1_tr1(const Tp1_04* handle);
static sc_boolean check_main_region_ESPERA_tr0_tr0(const Tp1_04* handle);
static sc_boolean check_main_region_ESPERA_tr1_tr1(const Tp1_04* handle);
static sc_boolean check_main_region_ESPERA_tr2_tr2(const Tp1_04* handle);
static sc_boolean check_PUERTA_ABRIR_tr0_tr0(const Tp1_04* handle);
static sc_boolean check_PUERTA_ABRIR_abrir_STOP_tr0_tr0(const Tp1_04* handle);
static sc_boolean check_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN_tr0_tr0(const Tp1_04* handle);
static sc_boolean check_PUERTA_ABRIR_abrir_ESPERA_tr0_tr0(const Tp1_04* handle);
static sc_boolean check_PUERTA_REPOSO_tr0_tr0(const Tp1_04* handle);
static sc_boolean check_PUERTA_REPOSO_tr1_tr1(const Tp1_04* handle);
static sc_boolean check_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP_tr0_tr0(const Tp1_04* handle);
static sc_boolean check_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP_tr1_tr1(const Tp1_04* handle);
static sc_boolean check_PUERTA_CERRAR_cerrar_STOP_tr0_tr0(const Tp1_04* handle);
static void effect_TECX_DEBOUNCE_tr0(Tp1_04* handle);
static void effect_TECX_NO_OPRIMIDO_tr0(Tp1_04* handle);
static void effect_TECX_OPRIMIDO_tr0(Tp1_04* handle);
static void effect_TECX_VALIDACION_tr0(Tp1_04* handle);
static void effect_TECX_VALIDACION_tr1(Tp1_04* handle);
static void effect_main_region_ESPERA_tr0(Tp1_04* handle);
static void effect_main_region_ESPERA_tr1(Tp1_04* handle);
static void effect_main_region_ESPERA_tr2(Tp1_04* handle);
static void effect_PUERTA_ABRIR_tr0(Tp1_04* handle);
static void effect_PUERTA_ABRIR_abrir_STOP_tr0(Tp1_04* handle);
static void effect_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN_tr0(Tp1_04* handle);
static void effect_PUERTA_ABRIR_abrir_ESPERA_tr0(Tp1_04* handle);
static void effect_PUERTA_REPOSO_tr0(Tp1_04* handle);
static void effect_PUERTA_REPOSO_tr1(Tp1_04* handle);
static void effect_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP_tr0(Tp1_04* handle);
static void effect_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP_tr1(Tp1_04* handle);
static void effect_PUERTA_CERRAR_cerrar_STOP_tr0(Tp1_04* handle);
static void enact_TECX_DEBOUNCE(Tp1_04* handle);
static void enact_TECX_OPRIMIDO(Tp1_04* handle);
static void enact_PUERTA_ABRIR_abrir_STOP(Tp1_04* handle);
static void enact_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN(Tp1_04* handle);
static void enact_PUERTA_ABRIR_abrir_ESPERA(Tp1_04* handle);
static void enact_PUERTA_REPOSO(Tp1_04* handle);
static void enact_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP(Tp1_04* handle);
static void enact_PUERTA_CERRAR_cerrar_STOP(Tp1_04* handle);
static void exact_TECX_DEBOUNCE(Tp1_04* handle);
static void exact_PUERTA_ABRIR_abrir_STOP(Tp1_04* handle);
static void exact_PUERTA_ABRIR_abrir_ESPERA(Tp1_04* handle);
static void exact_PUERTA_CERRAR_cerrar_STOP(Tp1_04* handle);
static void enseq_TECX_DEBOUNCE_default(Tp1_04* handle);
static void enseq_TECX_NO_OPRIMIDO_default(Tp1_04* handle);
static void enseq_TECX_OPRIMIDO_default(Tp1_04* handle);
static void enseq_TECX_VALIDACION_default(Tp1_04* handle);
static void enseq_main_region_ESPERA_default(Tp1_04* handle);
static void enseq_PUERTA_ABRIR_default(Tp1_04* handle);
static void enseq_PUERTA_ABRIR_abrir_STOP_default(Tp1_04* handle);
static void enseq_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN_default(Tp1_04* handle);
static void enseq_PUERTA_ABRIR_abrir_ESPERA_default(Tp1_04* handle);
static void enseq_PUERTA_REPOSO_default(Tp1_04* handle);
static void enseq_PUERTA_CERRAR_default(Tp1_04* handle);
static void enseq_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP_default(Tp1_04* handle);
static void enseq_PUERTA_CERRAR_cerrar_STOP_default(Tp1_04* handle);
static void enseq_TECX_default(Tp1_04* handle);
static void enseq_main_region_default(Tp1_04* handle);
static void enseq_PUERTA_default(Tp1_04* handle);
static void enseq_PUERTA_ABRIR_abrir_default(Tp1_04* handle);
static void enseq_PUERTA_CERRAR_cerrar_default(Tp1_04* handle);
static void exseq_TECX_DEBOUNCE(Tp1_04* handle);
static void exseq_TECX_NO_OPRIMIDO(Tp1_04* handle);
static void exseq_TECX_OPRIMIDO(Tp1_04* handle);
static void exseq_TECX_VALIDACION(Tp1_04* handle);
static void exseq_main_region_ESPERA(Tp1_04* handle);
static void exseq_PUERTA_ABRIR(Tp1_04* handle);
static void exseq_PUERTA_ABRIR_abrir_STOP(Tp1_04* handle);
static void exseq_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN(Tp1_04* handle);
static void exseq_PUERTA_ABRIR_abrir_ESPERA(Tp1_04* handle);
static void exseq_PUERTA_REPOSO(Tp1_04* handle);
static void exseq_PUERTA_CERRAR(Tp1_04* handle);
static void exseq_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP(Tp1_04* handle);
static void exseq_PUERTA_CERRAR_cerrar_STOP(Tp1_04* handle);
static void exseq_TECX(Tp1_04* handle);
static void exseq_main_region(Tp1_04* handle);
static void exseq_PUERTA(Tp1_04* handle);
static void exseq_PUERTA_ABRIR_abrir(Tp1_04* handle);
static void exseq_PUERTA_CERRAR_cerrar(Tp1_04* handle);
static void react_TECX_DEBOUNCE(Tp1_04* handle);
static void react_TECX_NO_OPRIMIDO(Tp1_04* handle);
static void react_TECX_OPRIMIDO(Tp1_04* handle);
static void react_TECX_VALIDACION(Tp1_04* handle);
static void react_main_region_ESPERA(Tp1_04* handle);
static void react_PUERTA_ABRIR_abrir_STOP(Tp1_04* handle);
static void react_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN(Tp1_04* handle);
static void react_PUERTA_ABRIR_abrir_ESPERA(Tp1_04* handle);
static void react_PUERTA_REPOSO(Tp1_04* handle);
static void react_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP(Tp1_04* handle);
static void react_PUERTA_CERRAR_cerrar_STOP(Tp1_04* handle);
static void react_TECX__entry_Default(Tp1_04* handle);
static void react_main_region__entry_Default(Tp1_04* handle);
static void react_PUERTA_ABRIR_abrir__entry_Default(Tp1_04* handle);
static void react_PUERTA__entry_Default(Tp1_04* handle);
static void react_PUERTA_CERRAR_cerrar__entry_Default(Tp1_04* handle);
static void clearInEvents(Tp1_04* handle);
static void clearOutEvents(Tp1_04* handle);

const sc_integer TP1_04_TP1_04IFACE_MOTORUP = 3;
const sc_integer TP1_04_TP1_04IFACE_MOTORDOWN = 4;
const sc_boolean TP1_04_TP1_04IFACE_MOTOR_ON = bool_true;
const sc_boolean TP1_04_TP1_04IFACE_MOTOR_OFF = bool_false;
const sc_integer TP1_04_TP1_04IFACE_SENSP = 1 << 0;
const sc_integer TP1_04_TP1_04IFACE_FCARRI = 1 << 1;
const sc_integer TP1_04_TP1_04IFACE_FCARRF = 1 << 2;

void tp1_04_init(Tp1_04* handle)
{
		sc_integer i;
	
		for (i = 0; i < TP1_04_MAX_ORTHOGONAL_STATES; ++i)
		{
			handle->stateConfVector[i] = Tp1_04_last_state;
		}
		
		
		handle->stateConfVectorPosition = 0;
	
		clearInEvents(handle);
		clearOutEvents(handle);
	
		/* Default init sequence for statechart tp1_04 */
		handle->internal.viTecla = 0;
}

void tp1_04_enter(Tp1_04* handle)
{
	/* Default enter sequence for statechart tp1_04 */
	enseq_TECX_default(handle);
	enseq_main_region_default(handle);
	enseq_PUERTA_default(handle);
}

void tp1_04_runCycle(Tp1_04* handle)
{
	clearOutEvents(handle);
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < TP1_04_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Tp1_04_TECX_DEBOUNCE:
		{
			react_TECX_DEBOUNCE(handle);
			break;
		}
		case Tp1_04_TECX_NO_OPRIMIDO:
		{
			react_TECX_NO_OPRIMIDO(handle);
			break;
		}
		case Tp1_04_TECX_OPRIMIDO:
		{
			react_TECX_OPRIMIDO(handle);
			break;
		}
		case Tp1_04_TECX_VALIDACION:
		{
			react_TECX_VALIDACION(handle);
			break;
		}
		case Tp1_04_main_region_ESPERA:
		{
			react_main_region_ESPERA(handle);
			break;
		}
		case Tp1_04_PUERTA_ABRIR_abrir_STOP:
		{
			react_PUERTA_ABRIR_abrir_STOP(handle);
			break;
		}
		case Tp1_04_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN:
		{
			react_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN(handle);
			break;
		}
		case Tp1_04_PUERTA_ABRIR_abrir_ESPERA:
		{
			react_PUERTA_ABRIR_abrir_ESPERA(handle);
			break;
		}
		case Tp1_04_PUERTA_REPOSO:
		{
			react_PUERTA_REPOSO(handle);
			break;
		}
		case Tp1_04_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP:
		{
			react_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP(handle);
			break;
		}
		case Tp1_04_PUERTA_CERRAR_cerrar_STOP:
		{
			react_PUERTA_CERRAR_cerrar_STOP(handle);
			break;
		}
		default:
			break;
		}
	}
	
	clearInEvents(handle);
}

void tp1_04_exit(Tp1_04* handle)
{
	/* Default exit sequence for statechart tp1_04 */
	exseq_TECX(handle);
	exseq_main_region(handle);
	exseq_PUERTA(handle);
}

sc_boolean tp1_04_isActive(const Tp1_04* handle)
{
	sc_boolean result = bool_false;
	int i;
	
	for(i = 0; i < TP1_04_MAX_ORTHOGONAL_STATES; i++)
	{
		result = result || handle->stateConfVector[i] != Tp1_04_last_state;
	}
	
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean tp1_04_isFinal(const Tp1_04* handle)
{
   return bool_false;
}

void tp1_04_raiseTimeEvent(Tp1_04* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(Tp1_04TimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean tp1_04_isStateActive(const Tp1_04* handle, Tp1_04States state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Tp1_04_TECX_DEBOUNCE :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_04_TECX_DEBOUNCE] == Tp1_04_TECX_DEBOUNCE
			);
			break;
		case Tp1_04_TECX_NO_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_04_TECX_NO_OPRIMIDO] == Tp1_04_TECX_NO_OPRIMIDO
			);
			break;
		case Tp1_04_TECX_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_04_TECX_OPRIMIDO] == Tp1_04_TECX_OPRIMIDO
			);
			break;
		case Tp1_04_TECX_VALIDACION :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_04_TECX_VALIDACION] == Tp1_04_TECX_VALIDACION
			);
			break;
		case Tp1_04_main_region_ESPERA :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_04_MAIN_REGION_ESPERA] == Tp1_04_main_region_ESPERA
			);
			break;
		case Tp1_04_PUERTA_ABRIR :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_04_PUERTA_ABRIR] >= Tp1_04_PUERTA_ABRIR
				&& handle->stateConfVector[SCVI_TP1_04_PUERTA_ABRIR] <= Tp1_04_PUERTA_ABRIR_abrir_ESPERA);
			break;
		case Tp1_04_PUERTA_ABRIR_abrir_STOP :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_04_PUERTA_ABRIR_ABRIR_STOP] == Tp1_04_PUERTA_ABRIR_abrir_STOP
			);
			break;
		case Tp1_04_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_04_PUERTA_ABRIR_ABRIR_PRENDER_MOTOR_DOWN] == Tp1_04_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN
			);
			break;
		case Tp1_04_PUERTA_ABRIR_abrir_ESPERA :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_04_PUERTA_ABRIR_ABRIR_ESPERA] == Tp1_04_PUERTA_ABRIR_abrir_ESPERA
			);
			break;
		case Tp1_04_PUERTA_REPOSO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_04_PUERTA_REPOSO] == Tp1_04_PUERTA_REPOSO
			);
			break;
		case Tp1_04_PUERTA_CERRAR :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_04_PUERTA_CERRAR] >= Tp1_04_PUERTA_CERRAR
				&& handle->stateConfVector[SCVI_TP1_04_PUERTA_CERRAR] <= Tp1_04_PUERTA_CERRAR_cerrar_STOP);
			break;
		case Tp1_04_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_04_PUERTA_CERRAR_CERRAR_PRENDER_MOTOR_UP] == Tp1_04_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP
			);
			break;
		case Tp1_04_PUERTA_CERRAR_cerrar_STOP :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_04_PUERTA_CERRAR_CERRAR_STOP] == Tp1_04_PUERTA_CERRAR_cerrar_STOP
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

static void clearInEvents(Tp1_04* handle)
{
	handle->iface.evTECXNoOprimido_raised = bool_false;
	handle->iface.evTECXOprimido_raised = bool_false;
	handle->internal.siTECXOK_raised = bool_false;
	handle->internal.siFinCarreraIni_raised = bool_false;
	handle->internal.siFinCarreraFin_raised = bool_false;
	handle->internal.siMotorUp_raised = bool_false;
	handle->internal.siMotorDown_raised = bool_false;
	handle->internal.siMotorOff_raised = bool_false;
	handle->timeEvents.tp1_04_TECX_DEBOUNCE_tev0_raised = bool_false;
	handle->timeEvents.tp1_04_PUERTA_ABRIR_abrir_STOP_tev0_raised = bool_false;
	handle->timeEvents.tp1_04_PUERTA_ABRIR_abrir_ESPERA_tev0_raised = bool_false;
	handle->timeEvents.tp1_04_PUERTA_CERRAR_cerrar_STOP_tev0_raised = bool_false;
}

static void clearOutEvents(Tp1_04* handle)
{
}

void tp1_04Iface_raise_evTECXNoOprimido(Tp1_04* handle)
{
	handle->iface.evTECXNoOprimido_raised = bool_true;
}
void tp1_04Iface_raise_evTECXOprimido(Tp1_04* handle, sc_integer value)
{
	handle->iface.evTECXOprimido_value = value;
	handle->iface.evTECXOprimido_raised = bool_true;
}


const sc_integer tp1_04Iface_get_mOTORUP(const Tp1_04* handle)
{
	return TP1_04_TP1_04IFACE_MOTORUP;
}
const sc_integer tp1_04Iface_get_mOTORDOWN(const Tp1_04* handle)
{
	return TP1_04_TP1_04IFACE_MOTORDOWN;
}
const sc_boolean tp1_04Iface_get_mOTOR_ON(const Tp1_04* handle)
{
	return TP1_04_TP1_04IFACE_MOTOR_ON;
}
const sc_boolean tp1_04Iface_get_mOTOR_OFF(const Tp1_04* handle)
{
	return TP1_04_TP1_04IFACE_MOTOR_OFF;
}
const sc_integer tp1_04Iface_get_sENSP(const Tp1_04* handle)
{
	return TP1_04_TP1_04IFACE_SENSP;
}
const sc_integer tp1_04Iface_get_fCARRI(const Tp1_04* handle)
{
	return TP1_04_TP1_04IFACE_FCARRI;
}
const sc_integer tp1_04Iface_get_fCARRF(const Tp1_04* handle)
{
	return TP1_04_TP1_04IFACE_FCARRF;
}

/* implementations of all internal functions */

static sc_boolean check_TECX_DEBOUNCE_tr0_tr0(const Tp1_04* handle)
{
	return handle->timeEvents.tp1_04_TECX_DEBOUNCE_tev0_raised;
}

static sc_boolean check_TECX_NO_OPRIMIDO_tr0_tr0(const Tp1_04* handle)
{
	return handle->iface.evTECXOprimido_raised;
}

static sc_boolean check_TECX_OPRIMIDO_tr0_tr0(const Tp1_04* handle)
{
	return handle->iface.evTECXNoOprimido_raised;
}

static sc_boolean check_TECX_VALIDACION_tr0_tr0(const Tp1_04* handle)
{
	return handle->iface.evTECXOprimido_raised;
}

static sc_boolean check_TECX_VALIDACION_tr1_tr1(const Tp1_04* handle)
{
	return handle->iface.evTECXNoOprimido_raised;
}

static sc_boolean check_main_region_ESPERA_tr0_tr0(const Tp1_04* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == TP1_04_TP1_04IFACE_SENSP)) ? bool_true : bool_false;
}

static sc_boolean check_main_region_ESPERA_tr1_tr1(const Tp1_04* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == TP1_04_TP1_04IFACE_FCARRI)) ? bool_true : bool_false;
}

static sc_boolean check_main_region_ESPERA_tr2_tr2(const Tp1_04* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == TP1_04_TP1_04IFACE_FCARRF)) ? bool_true : bool_false;
}

static sc_boolean check_PUERTA_ABRIR_tr0_tr0(const Tp1_04* handle)
{
	return handle->internal.siMotorOff_raised;
}

static sc_boolean check_PUERTA_ABRIR_abrir_STOP_tr0_tr0(const Tp1_04* handle)
{
	return handle->timeEvents.tp1_04_PUERTA_ABRIR_abrir_STOP_tev0_raised;
}

static sc_boolean check_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN_tr0_tr0(const Tp1_04* handle)
{
	return handle->internal.siFinCarreraIni_raised;
}

static sc_boolean check_PUERTA_ABRIR_abrir_ESPERA_tr0_tr0(const Tp1_04* handle)
{
	return handle->timeEvents.tp1_04_PUERTA_ABRIR_abrir_ESPERA_tev0_raised;
}

static sc_boolean check_PUERTA_REPOSO_tr0_tr0(const Tp1_04* handle)
{
	return handle->internal.siMotorDown_raised;
}

static sc_boolean check_PUERTA_REPOSO_tr1_tr1(const Tp1_04* handle)
{
	return handle->internal.siMotorUp_raised;
}

static sc_boolean check_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP_tr0_tr0(const Tp1_04* handle)
{
	return handle->internal.siFinCarreraFin_raised;
}

static sc_boolean check_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP_tr1_tr1(const Tp1_04* handle)
{
	return handle->internal.siMotorDown_raised;
}

static sc_boolean check_PUERTA_CERRAR_cerrar_STOP_tr0_tr0(const Tp1_04* handle)
{
	return handle->timeEvents.tp1_04_PUERTA_CERRAR_cerrar_STOP_tev0_raised;
}

static void effect_TECX_DEBOUNCE_tr0(Tp1_04* handle)
{
	exseq_TECX_DEBOUNCE(handle);
	enseq_TECX_VALIDACION_default(handle);
}

static void effect_TECX_NO_OPRIMIDO_tr0(Tp1_04* handle)
{
	exseq_TECX_NO_OPRIMIDO(handle);
	enseq_TECX_DEBOUNCE_default(handle);
}

static void effect_TECX_OPRIMIDO_tr0(Tp1_04* handle)
{
	exseq_TECX_OPRIMIDO(handle);
	enseq_TECX_NO_OPRIMIDO_default(handle);
}

static void effect_TECX_VALIDACION_tr0(Tp1_04* handle)
{
	exseq_TECX_VALIDACION(handle);
	enseq_TECX_OPRIMIDO_default(handle);
}

static void effect_TECX_VALIDACION_tr1(Tp1_04* handle)
{
	exseq_TECX_VALIDACION(handle);
	enseq_TECX_NO_OPRIMIDO_default(handle);
}

static void effect_main_region_ESPERA_tr0(Tp1_04* handle)
{
	exseq_main_region_ESPERA(handle);
	handle->internal.siMotorDown_raised = bool_true;
	enseq_main_region_ESPERA_default(handle);
}

static void effect_main_region_ESPERA_tr1(Tp1_04* handle)
{
	exseq_main_region_ESPERA(handle);
	handle->internal.siFinCarreraIni_raised = bool_true;
	enseq_main_region_ESPERA_default(handle);
}

static void effect_main_region_ESPERA_tr2(Tp1_04* handle)
{
	exseq_main_region_ESPERA(handle);
	handle->internal.siFinCarreraFin_raised = bool_true;
	enseq_main_region_ESPERA_default(handle);
}

static void effect_PUERTA_ABRIR_tr0(Tp1_04* handle)
{
	exseq_PUERTA_ABRIR(handle);
	enseq_PUERTA_REPOSO_default(handle);
}

static void effect_PUERTA_ABRIR_abrir_STOP_tr0(Tp1_04* handle)
{
	exseq_PUERTA_ABRIR(handle);
	enseq_PUERTA_CERRAR_default(handle);
}

static void effect_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN_tr0(Tp1_04* handle)
{
	exseq_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN(handle);
	enseq_PUERTA_ABRIR_abrir_ESPERA_default(handle);
}

static void effect_PUERTA_ABRIR_abrir_ESPERA_tr0(Tp1_04* handle)
{
	exseq_PUERTA_ABRIR_abrir_ESPERA(handle);
	enseq_PUERTA_ABRIR_abrir_STOP_default(handle);
}

static void effect_PUERTA_REPOSO_tr0(Tp1_04* handle)
{
	exseq_PUERTA_REPOSO(handle);
	enseq_PUERTA_ABRIR_default(handle);
}

static void effect_PUERTA_REPOSO_tr1(Tp1_04* handle)
{
	exseq_PUERTA_REPOSO(handle);
	enseq_PUERTA_CERRAR_default(handle);
}

static void effect_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP_tr0(Tp1_04* handle)
{
	exseq_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP(handle);
	enseq_PUERTA_CERRAR_cerrar_STOP_default(handle);
}

static void effect_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP_tr1(Tp1_04* handle)
{
	exseq_PUERTA_CERRAR(handle);
	enseq_PUERTA_ABRIR_default(handle);
}

static void effect_PUERTA_CERRAR_cerrar_STOP_tr0(Tp1_04* handle)
{
	exseq_PUERTA_CERRAR(handle);
	enseq_PUERTA_REPOSO_default(handle);
}

/* Entry action for state 'DEBOUNCE'. */
static void enact_TECX_DEBOUNCE(Tp1_04* handle)
{
	/* Entry action for state 'DEBOUNCE'. */
	tp1_04_setTimer(handle, (sc_eventid) &(handle->timeEvents.tp1_04_TECX_DEBOUNCE_tev0_raised) , 100, bool_false);
}

/* Entry action for state 'OPRIMIDO'. */
static void enact_TECX_OPRIMIDO(Tp1_04* handle)
{
	/* Entry action for state 'OPRIMIDO'. */
	handle->internal.siTECXOK_raised = bool_true;
	handle->internal.viTecla = handle->iface.evTECXOprimido_value;
}

/* Entry action for state 'STOP'. */
static void enact_PUERTA_ABRIR_abrir_STOP(Tp1_04* handle)
{
	/* Entry action for state 'STOP'. */
	tp1_04_setTimer(handle, (sc_eventid) &(handle->timeEvents.tp1_04_PUERTA_ABRIR_abrir_STOP_tev0_raised) , 50, bool_false);
	handle->internal.siMotorUp_raised = bool_true;
}

/* Entry action for state 'PRENDER MOTOR DOWN'. */
static void enact_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN(Tp1_04* handle)
{
	/* Entry action for state 'PRENDER MOTOR DOWN'. */
	tp1_04Iface_opMOTOR(handle, TP1_04_TP1_04IFACE_MOTORUP, TP1_04_TP1_04IFACE_MOTOR_OFF);
	tp1_04Iface_opMOTOR(handle, TP1_04_TP1_04IFACE_MOTORDOWN, TP1_04_TP1_04IFACE_MOTOR_ON);
}

/* Entry action for state 'ESPERA'. */
static void enact_PUERTA_ABRIR_abrir_ESPERA(Tp1_04* handle)
{
	/* Entry action for state 'ESPERA'. */
	tp1_04_setTimer(handle, (sc_eventid) &(handle->timeEvents.tp1_04_PUERTA_ABRIR_abrir_ESPERA_tev0_raised) , 5000, bool_false);
	tp1_04Iface_opMOTOR(handle, TP1_04_TP1_04IFACE_MOTORDOWN, TP1_04_TP1_04IFACE_MOTOR_OFF);
}

/* Entry action for state 'REPOSO'. */
static void enact_PUERTA_REPOSO(Tp1_04* handle)
{
	/* Entry action for state 'REPOSO'. */
	tp1_04Iface_opMOTOR(handle, TP1_04_TP1_04IFACE_MOTORDOWN, TP1_04_TP1_04IFACE_MOTOR_OFF);
	tp1_04Iface_opMOTOR(handle, TP1_04_TP1_04IFACE_MOTORUP, TP1_04_TP1_04IFACE_MOTOR_OFF);
}

/* Entry action for state 'PRENDER MOTOR UP'. */
static void enact_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP(Tp1_04* handle)
{
	/* Entry action for state 'PRENDER MOTOR UP'. */
	tp1_04Iface_opMOTOR(handle, TP1_04_TP1_04IFACE_MOTORUP, TP1_04_TP1_04IFACE_MOTOR_ON);
	tp1_04Iface_opMOTOR(handle, TP1_04_TP1_04IFACE_MOTORDOWN, TP1_04_TP1_04IFACE_MOTOR_OFF);
}

/* Entry action for state 'STOP'. */
static void enact_PUERTA_CERRAR_cerrar_STOP(Tp1_04* handle)
{
	/* Entry action for state 'STOP'. */
	tp1_04_setTimer(handle, (sc_eventid) &(handle->timeEvents.tp1_04_PUERTA_CERRAR_cerrar_STOP_tev0_raised) , 50, bool_false);
	tp1_04Iface_opMOTOR(handle, TP1_04_TP1_04IFACE_MOTORUP, TP1_04_TP1_04IFACE_MOTOR_OFF);
	handle->internal.siMotorOff_raised = bool_true;
}

/* Exit action for state 'DEBOUNCE'. */
static void exact_TECX_DEBOUNCE(Tp1_04* handle)
{
	/* Exit action for state 'DEBOUNCE'. */
	tp1_04_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.tp1_04_TECX_DEBOUNCE_tev0_raised) );		
}

/* Exit action for state 'STOP'. */
static void exact_PUERTA_ABRIR_abrir_STOP(Tp1_04* handle)
{
	/* Exit action for state 'STOP'. */
	tp1_04_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.tp1_04_PUERTA_ABRIR_abrir_STOP_tev0_raised) );		
}

/* Exit action for state 'ESPERA'. */
static void exact_PUERTA_ABRIR_abrir_ESPERA(Tp1_04* handle)
{
	/* Exit action for state 'ESPERA'. */
	tp1_04_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.tp1_04_PUERTA_ABRIR_abrir_ESPERA_tev0_raised) );		
}

/* Exit action for state 'STOP'. */
static void exact_PUERTA_CERRAR_cerrar_STOP(Tp1_04* handle)
{
	/* Exit action for state 'STOP'. */
	tp1_04_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.tp1_04_PUERTA_CERRAR_cerrar_STOP_tev0_raised) );		
}

/* 'default' enter sequence for state DEBOUNCE */
static void enseq_TECX_DEBOUNCE_default(Tp1_04* handle)
{
	/* 'default' enter sequence for state DEBOUNCE */
	enact_TECX_DEBOUNCE(handle);
	handle->stateConfVector[0] = Tp1_04_TECX_DEBOUNCE;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state NO_OPRIMIDO */
static void enseq_TECX_NO_OPRIMIDO_default(Tp1_04* handle)
{
	/* 'default' enter sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Tp1_04_TECX_NO_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state OPRIMIDO */
static void enseq_TECX_OPRIMIDO_default(Tp1_04* handle)
{
	/* 'default' enter sequence for state OPRIMIDO */
	enact_TECX_OPRIMIDO(handle);
	handle->stateConfVector[0] = Tp1_04_TECX_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state VALIDACION */
static void enseq_TECX_VALIDACION_default(Tp1_04* handle)
{
	/* 'default' enter sequence for state VALIDACION */
	handle->stateConfVector[0] = Tp1_04_TECX_VALIDACION;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state ESPERA */
static void enseq_main_region_ESPERA_default(Tp1_04* handle)
{
	/* 'default' enter sequence for state ESPERA */
	handle->stateConfVector[1] = Tp1_04_main_region_ESPERA;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state ABRIR */
static void enseq_PUERTA_ABRIR_default(Tp1_04* handle)
{
	/* 'default' enter sequence for state ABRIR */
	enseq_PUERTA_ABRIR_abrir_default(handle);
}

/* 'default' enter sequence for state STOP */
static void enseq_PUERTA_ABRIR_abrir_STOP_default(Tp1_04* handle)
{
	/* 'default' enter sequence for state STOP */
	enact_PUERTA_ABRIR_abrir_STOP(handle);
	handle->stateConfVector[2] = Tp1_04_PUERTA_ABRIR_abrir_STOP;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state PRENDER MOTOR DOWN */
static void enseq_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN_default(Tp1_04* handle)
{
	/* 'default' enter sequence for state PRENDER MOTOR DOWN */
	enact_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN(handle);
	handle->stateConfVector[2] = Tp1_04_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state ESPERA */
static void enseq_PUERTA_ABRIR_abrir_ESPERA_default(Tp1_04* handle)
{
	/* 'default' enter sequence for state ESPERA */
	enact_PUERTA_ABRIR_abrir_ESPERA(handle);
	handle->stateConfVector[2] = Tp1_04_PUERTA_ABRIR_abrir_ESPERA;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state REPOSO */
static void enseq_PUERTA_REPOSO_default(Tp1_04* handle)
{
	/* 'default' enter sequence for state REPOSO */
	enact_PUERTA_REPOSO(handle);
	handle->stateConfVector[2] = Tp1_04_PUERTA_REPOSO;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state CERRAR */
static void enseq_PUERTA_CERRAR_default(Tp1_04* handle)
{
	/* 'default' enter sequence for state CERRAR */
	enseq_PUERTA_CERRAR_cerrar_default(handle);
}

/* 'default' enter sequence for state PRENDER MOTOR UP */
static void enseq_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP_default(Tp1_04* handle)
{
	/* 'default' enter sequence for state PRENDER MOTOR UP */
	enact_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP(handle);
	handle->stateConfVector[2] = Tp1_04_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state STOP */
static void enseq_PUERTA_CERRAR_cerrar_STOP_default(Tp1_04* handle)
{
	/* 'default' enter sequence for state STOP */
	enact_PUERTA_CERRAR_cerrar_STOP(handle);
	handle->stateConfVector[2] = Tp1_04_PUERTA_CERRAR_cerrar_STOP;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for region TECX */
static void enseq_TECX_default(Tp1_04* handle)
{
	/* 'default' enter sequence for region TECX */
	react_TECX__entry_Default(handle);
}

/* 'default' enter sequence for region main region */
static void enseq_main_region_default(Tp1_04* handle)
{
	/* 'default' enter sequence for region main region */
	react_main_region__entry_Default(handle);
}

/* 'default' enter sequence for region PUERTA */
static void enseq_PUERTA_default(Tp1_04* handle)
{
	/* 'default' enter sequence for region PUERTA */
	react_PUERTA__entry_Default(handle);
}

/* 'default' enter sequence for region abrir */
static void enseq_PUERTA_ABRIR_abrir_default(Tp1_04* handle)
{
	/* 'default' enter sequence for region abrir */
	react_PUERTA_ABRIR_abrir__entry_Default(handle);
}

/* 'default' enter sequence for region cerrar */
static void enseq_PUERTA_CERRAR_cerrar_default(Tp1_04* handle)
{
	/* 'default' enter sequence for region cerrar */
	react_PUERTA_CERRAR_cerrar__entry_Default(handle);
}

/* Default exit sequence for state DEBOUNCE */
static void exseq_TECX_DEBOUNCE(Tp1_04* handle)
{
	/* Default exit sequence for state DEBOUNCE */
	handle->stateConfVector[0] = Tp1_04_last_state;
	handle->stateConfVectorPosition = 0;
	exact_TECX_DEBOUNCE(handle);
}

/* Default exit sequence for state NO_OPRIMIDO */
static void exseq_TECX_NO_OPRIMIDO(Tp1_04* handle)
{
	/* Default exit sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Tp1_04_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state OPRIMIDO */
static void exseq_TECX_OPRIMIDO(Tp1_04* handle)
{
	/* Default exit sequence for state OPRIMIDO */
	handle->stateConfVector[0] = Tp1_04_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state VALIDACION */
static void exseq_TECX_VALIDACION(Tp1_04* handle)
{
	/* Default exit sequence for state VALIDACION */
	handle->stateConfVector[0] = Tp1_04_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state ESPERA */
static void exseq_main_region_ESPERA(Tp1_04* handle)
{
	/* Default exit sequence for state ESPERA */
	handle->stateConfVector[1] = Tp1_04_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state ABRIR */
static void exseq_PUERTA_ABRIR(Tp1_04* handle)
{
	/* Default exit sequence for state ABRIR */
	exseq_PUERTA_ABRIR_abrir(handle);
}

/* Default exit sequence for state STOP */
static void exseq_PUERTA_ABRIR_abrir_STOP(Tp1_04* handle)
{
	/* Default exit sequence for state STOP */
	handle->stateConfVector[2] = Tp1_04_last_state;
	handle->stateConfVectorPosition = 2;
	exact_PUERTA_ABRIR_abrir_STOP(handle);
}

/* Default exit sequence for state PRENDER MOTOR DOWN */
static void exseq_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN(Tp1_04* handle)
{
	/* Default exit sequence for state PRENDER MOTOR DOWN */
	handle->stateConfVector[2] = Tp1_04_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state ESPERA */
static void exseq_PUERTA_ABRIR_abrir_ESPERA(Tp1_04* handle)
{
	/* Default exit sequence for state ESPERA */
	handle->stateConfVector[2] = Tp1_04_last_state;
	handle->stateConfVectorPosition = 2;
	exact_PUERTA_ABRIR_abrir_ESPERA(handle);
}

/* Default exit sequence for state REPOSO */
static void exseq_PUERTA_REPOSO(Tp1_04* handle)
{
	/* Default exit sequence for state REPOSO */
	handle->stateConfVector[2] = Tp1_04_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state CERRAR */
static void exseq_PUERTA_CERRAR(Tp1_04* handle)
{
	/* Default exit sequence for state CERRAR */
	exseq_PUERTA_CERRAR_cerrar(handle);
}

/* Default exit sequence for state PRENDER MOTOR UP */
static void exseq_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP(Tp1_04* handle)
{
	/* Default exit sequence for state PRENDER MOTOR UP */
	handle->stateConfVector[2] = Tp1_04_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state STOP */
static void exseq_PUERTA_CERRAR_cerrar_STOP(Tp1_04* handle)
{
	/* Default exit sequence for state STOP */
	handle->stateConfVector[2] = Tp1_04_last_state;
	handle->stateConfVectorPosition = 2;
	exact_PUERTA_CERRAR_cerrar_STOP(handle);
}

/* Default exit sequence for region TECX */
static void exseq_TECX(Tp1_04* handle)
{
	/* Default exit sequence for region TECX */
	/* Handle exit of all possible states (of tp1_04.TECX) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Tp1_04_TECX_DEBOUNCE :
		{
			exseq_TECX_DEBOUNCE(handle);
			break;
		}
		case Tp1_04_TECX_NO_OPRIMIDO :
		{
			exseq_TECX_NO_OPRIMIDO(handle);
			break;
		}
		case Tp1_04_TECX_OPRIMIDO :
		{
			exseq_TECX_OPRIMIDO(handle);
			break;
		}
		case Tp1_04_TECX_VALIDACION :
		{
			exseq_TECX_VALIDACION(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region main region */
static void exseq_main_region(Tp1_04* handle)
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of tp1_04.main_region) at position 1... */
	switch(handle->stateConfVector[ 1 ])
	{
		case Tp1_04_main_region_ESPERA :
		{
			exseq_main_region_ESPERA(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region PUERTA */
static void exseq_PUERTA(Tp1_04* handle)
{
	/* Default exit sequence for region PUERTA */
	/* Handle exit of all possible states (of tp1_04.PUERTA) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case Tp1_04_PUERTA_ABRIR_abrir_STOP :
		{
			exseq_PUERTA_ABRIR_abrir_STOP(handle);
			break;
		}
		case Tp1_04_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN :
		{
			exseq_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN(handle);
			break;
		}
		case Tp1_04_PUERTA_ABRIR_abrir_ESPERA :
		{
			exseq_PUERTA_ABRIR_abrir_ESPERA(handle);
			break;
		}
		case Tp1_04_PUERTA_REPOSO :
		{
			exseq_PUERTA_REPOSO(handle);
			break;
		}
		case Tp1_04_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP :
		{
			exseq_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP(handle);
			break;
		}
		case Tp1_04_PUERTA_CERRAR_cerrar_STOP :
		{
			exseq_PUERTA_CERRAR_cerrar_STOP(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region abrir */
static void exseq_PUERTA_ABRIR_abrir(Tp1_04* handle)
{
	/* Default exit sequence for region abrir */
	/* Handle exit of all possible states (of tp1_04.PUERTA.ABRIR.abrir) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case Tp1_04_PUERTA_ABRIR_abrir_STOP :
		{
			exseq_PUERTA_ABRIR_abrir_STOP(handle);
			break;
		}
		case Tp1_04_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN :
		{
			exseq_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN(handle);
			break;
		}
		case Tp1_04_PUERTA_ABRIR_abrir_ESPERA :
		{
			exseq_PUERTA_ABRIR_abrir_ESPERA(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region cerrar */
static void exseq_PUERTA_CERRAR_cerrar(Tp1_04* handle)
{
	/* Default exit sequence for region cerrar */
	/* Handle exit of all possible states (of tp1_04.PUERTA.CERRAR.cerrar) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case Tp1_04_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP :
		{
			exseq_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP(handle);
			break;
		}
		case Tp1_04_PUERTA_CERRAR_cerrar_STOP :
		{
			exseq_PUERTA_CERRAR_cerrar_STOP(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state DEBOUNCE. */
static void react_TECX_DEBOUNCE(Tp1_04* handle)
{
	/* The reactions of state DEBOUNCE. */
	if (check_TECX_DEBOUNCE_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_DEBOUNCE_tr0(handle);
	} 
}

/* The reactions of state NO_OPRIMIDO. */
static void react_TECX_NO_OPRIMIDO(Tp1_04* handle)
{
	/* The reactions of state NO_OPRIMIDO. */
	if (check_TECX_NO_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_NO_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state OPRIMIDO. */
static void react_TECX_OPRIMIDO(Tp1_04* handle)
{
	/* The reactions of state OPRIMIDO. */
	if (check_TECX_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state VALIDACION. */
static void react_TECX_VALIDACION(Tp1_04* handle)
{
	/* The reactions of state VALIDACION. */
	if (check_TECX_VALIDACION_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_VALIDACION_tr0(handle);
	}  else
	{
		if (check_TECX_VALIDACION_tr1_tr1(handle) == bool_true)
		{ 
			effect_TECX_VALIDACION_tr1(handle);
		} 
	}
}

/* The reactions of state ESPERA. */
static void react_main_region_ESPERA(Tp1_04* handle)
{
	/* The reactions of state ESPERA. */
	if (check_main_region_ESPERA_tr0_tr0(handle) == bool_true)
	{ 
		effect_main_region_ESPERA_tr0(handle);
	}  else
	{
		if (check_main_region_ESPERA_tr1_tr1(handle) == bool_true)
		{ 
			effect_main_region_ESPERA_tr1(handle);
		}  else
		{
			if (check_main_region_ESPERA_tr2_tr2(handle) == bool_true)
			{ 
				effect_main_region_ESPERA_tr2(handle);
			} 
		}
	}
}

/* The reactions of state STOP. */
static void react_PUERTA_ABRIR_abrir_STOP(Tp1_04* handle)
{
	/* The reactions of state STOP. */
	if (check_PUERTA_ABRIR_tr0_tr0(handle) == bool_true)
	{ 
		effect_PUERTA_ABRIR_tr0(handle);
	}  else
	{
		if (check_PUERTA_ABRIR_abrir_STOP_tr0_tr0(handle) == bool_true)
		{ 
			effect_PUERTA_ABRIR_abrir_STOP_tr0(handle);
		} 
	}
}

/* The reactions of state PRENDER MOTOR DOWN. */
static void react_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN(Tp1_04* handle)
{
	/* The reactions of state PRENDER MOTOR DOWN. */
	if (check_PUERTA_ABRIR_tr0_tr0(handle) == bool_true)
	{ 
		effect_PUERTA_ABRIR_tr0(handle);
	}  else
	{
		if (check_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN_tr0_tr0(handle) == bool_true)
		{ 
			effect_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN_tr0(handle);
		} 
	}
}

/* The reactions of state ESPERA. */
static void react_PUERTA_ABRIR_abrir_ESPERA(Tp1_04* handle)
{
	/* The reactions of state ESPERA. */
	if (check_PUERTA_ABRIR_tr0_tr0(handle) == bool_true)
	{ 
		effect_PUERTA_ABRIR_tr0(handle);
	}  else
	{
		if (check_PUERTA_ABRIR_abrir_ESPERA_tr0_tr0(handle) == bool_true)
		{ 
			effect_PUERTA_ABRIR_abrir_ESPERA_tr0(handle);
		} 
	}
}

/* The reactions of state REPOSO. */
static void react_PUERTA_REPOSO(Tp1_04* handle)
{
	/* The reactions of state REPOSO. */
	if (check_PUERTA_REPOSO_tr0_tr0(handle) == bool_true)
	{ 
		effect_PUERTA_REPOSO_tr0(handle);
	}  else
	{
		if (check_PUERTA_REPOSO_tr1_tr1(handle) == bool_true)
		{ 
			effect_PUERTA_REPOSO_tr1(handle);
		} 
	}
}

/* The reactions of state PRENDER MOTOR UP. */
static void react_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP(Tp1_04* handle)
{
	/* The reactions of state PRENDER MOTOR UP. */
	if (check_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP_tr0_tr0(handle) == bool_true)
	{ 
		effect_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP_tr0(handle);
	}  else
	{
		if (check_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP_tr1_tr1(handle) == bool_true)
		{ 
			effect_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP_tr1(handle);
		} 
	}
}

/* The reactions of state STOP. */
static void react_PUERTA_CERRAR_cerrar_STOP(Tp1_04* handle)
{
	/* The reactions of state STOP. */
	if (check_PUERTA_CERRAR_cerrar_STOP_tr0_tr0(handle) == bool_true)
	{ 
		effect_PUERTA_CERRAR_cerrar_STOP_tr0(handle);
	} 
}

/* Default react sequence for initial entry  */
static void react_TECX__entry_Default(Tp1_04* handle)
{
	/* Default react sequence for initial entry  */
	enseq_TECX_NO_OPRIMIDO_default(handle);
}

/* Default react sequence for initial entry  */
static void react_main_region__entry_Default(Tp1_04* handle)
{
	/* Default react sequence for initial entry  */
	enseq_main_region_ESPERA_default(handle);
}

/* Default react sequence for initial entry  */
static void react_PUERTA_ABRIR_abrir__entry_Default(Tp1_04* handle)
{
	/* Default react sequence for initial entry  */
	enseq_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN_default(handle);
}

/* Default react sequence for initial entry  */
static void react_PUERTA__entry_Default(Tp1_04* handle)
{
	/* Default react sequence for initial entry  */
	enseq_PUERTA_REPOSO_default(handle);
}

/* Default react sequence for initial entry  */
static void react_PUERTA_CERRAR_cerrar__entry_Default(Tp1_04* handle)
{
	/* Default react sequence for initial entry  */
	enseq_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP_default(handle);
}


