
#include "Tp1_07.h"
#include "..\inc\sc_types.h"
#include "Tp1_07Required.h"

#include <stdlib.h>
#include <string.h>
/*! \file Implementation of the state machine 'tp1_07'
*/

/* prototypes of all internal functions */
static sc_boolean check_TECX_DEBOUNCE_tr0_tr0(const Tp1_07* handle);
static sc_boolean check_TECX_NO_OPRIMIDO_tr0_tr0(const Tp1_07* handle);
static sc_boolean check_TECX_OPRIMIDO_tr0_tr0(const Tp1_07* handle);
static sc_boolean check_TECX_VALIDACION_tr0_tr0(const Tp1_07* handle);
static sc_boolean check_TECX_VALIDACION_tr1_tr1(const Tp1_07* handle);
static sc_boolean check_main_region_ESPERA_tr0_tr0(const Tp1_07* handle);
static sc_boolean check_main_region_ESPERA_tr1_tr1(const Tp1_07* handle);
static sc_boolean check_main_region_ESPERA_tr2_tr2(const Tp1_07* handle);
static sc_boolean check_modo_INICIAL_tr0_tr0(const Tp1_07* handle);
static sc_boolean check_modo_SETMODO1_tr0_tr0(const Tp1_07* handle);
static sc_boolean check_modo_SETMODO2_tr0_tr0(const Tp1_07* handle);
static sc_boolean check_modo_SETMODO3_tr0_tr0(const Tp1_07* handle);
static sc_boolean check_se_ales_OFF_tr0_tr0(const Tp1_07* handle);
static sc_boolean check_se_ales_ON_tr0_tr0(const Tp1_07* handle);
static sc_boolean check_MICRO_OFF_tr0_tr0(const Tp1_07* handle);
static sc_boolean check_MICRO_ON_tr0_tr0(const Tp1_07* handle);
static sc_boolean check_MICRO_ON_tr1_tr1(const Tp1_07* handle);
static void effect_TECX_DEBOUNCE_tr0(Tp1_07* handle);
static void effect_TECX_NO_OPRIMIDO_tr0(Tp1_07* handle);
static void effect_TECX_OPRIMIDO_tr0(Tp1_07* handle);
static void effect_TECX_VALIDACION_tr0(Tp1_07* handle);
static void effect_TECX_VALIDACION_tr1(Tp1_07* handle);
static void effect_main_region_ESPERA_tr0(Tp1_07* handle);
static void effect_main_region_ESPERA_tr1(Tp1_07* handle);
static void effect_main_region_ESPERA_tr2(Tp1_07* handle);
static void effect_modo_INICIAL_tr0(Tp1_07* handle);
static void effect_modo_SETMODO1_tr0(Tp1_07* handle);
static void effect_modo_SETMODO2_tr0(Tp1_07* handle);
static void effect_modo_SETMODO3_tr0(Tp1_07* handle);
static void effect_se_ales_OFF_tr0(Tp1_07* handle);
static void effect_se_ales_ON_tr0(Tp1_07* handle);
static void effect_MICRO_OFF_tr0(Tp1_07* handle);
static void effect_MICRO_ON_tr0(Tp1_07* handle);
static void effect_MICRO_ON_tr1(Tp1_07* handle);
static void enact_TECX_DEBOUNCE(Tp1_07* handle);
static void enact_TECX_OPRIMIDO(Tp1_07* handle);
static void enact_modo_INICIAL(Tp1_07* handle);
static void enact_modo_SETMODO1(Tp1_07* handle);
static void enact_modo_SETMODO2(Tp1_07* handle);
static void enact_modo_SETMODO3(Tp1_07* handle);
static void enact_se_ales_OFF(Tp1_07* handle);
static void enact_MICRO_OFF(Tp1_07* handle);
static void enact_MICRO_ON(Tp1_07* handle);
static void exact_TECX_DEBOUNCE(Tp1_07* handle);
static void enseq_TECX_DEBOUNCE_default(Tp1_07* handle);
static void enseq_TECX_NO_OPRIMIDO_default(Tp1_07* handle);
static void enseq_TECX_OPRIMIDO_default(Tp1_07* handle);
static void enseq_TECX_VALIDACION_default(Tp1_07* handle);
static void enseq_main_region_ESPERA_default(Tp1_07* handle);
static void enseq_modo_INICIAL_default(Tp1_07* handle);
static void enseq_modo_SETMODO1_default(Tp1_07* handle);
static void enseq_modo_SETMODO2_default(Tp1_07* handle);
static void enseq_modo_SETMODO3_default(Tp1_07* handle);
static void enseq_se_ales_OFF_default(Tp1_07* handle);
static void enseq_se_ales_ON_default(Tp1_07* handle);
static void enseq_MICRO_OFF_default(Tp1_07* handle);
static void enseq_MICRO_ON_default(Tp1_07* handle);
static void enseq_TECX_default(Tp1_07* handle);
static void enseq_main_region_default(Tp1_07* handle);
static void enseq_modo_default(Tp1_07* handle);
static void enseq_se_ales_default(Tp1_07* handle);
static void enseq_MICRO_default(Tp1_07* handle);
static void exseq_TECX_DEBOUNCE(Tp1_07* handle);
static void exseq_TECX_NO_OPRIMIDO(Tp1_07* handle);
static void exseq_TECX_OPRIMIDO(Tp1_07* handle);
static void exseq_TECX_VALIDACION(Tp1_07* handle);
static void exseq_main_region_ESPERA(Tp1_07* handle);
static void exseq_modo_INICIAL(Tp1_07* handle);
static void exseq_modo_SETMODO1(Tp1_07* handle);
static void exseq_modo_SETMODO2(Tp1_07* handle);
static void exseq_modo_SETMODO3(Tp1_07* handle);
static void exseq_se_ales_OFF(Tp1_07* handle);
static void exseq_se_ales_ON(Tp1_07* handle);
static void exseq_MICRO_OFF(Tp1_07* handle);
static void exseq_MICRO_ON(Tp1_07* handle);
static void exseq_TECX(Tp1_07* handle);
static void exseq_main_region(Tp1_07* handle);
static void exseq_modo(Tp1_07* handle);
static void exseq_se_ales(Tp1_07* handle);
static void exseq_MICRO(Tp1_07* handle);
static void react_TECX_DEBOUNCE(Tp1_07* handle);
static void react_TECX_NO_OPRIMIDO(Tp1_07* handle);
static void react_TECX_OPRIMIDO(Tp1_07* handle);
static void react_TECX_VALIDACION(Tp1_07* handle);
static void react_main_region_ESPERA(Tp1_07* handle);
static void react_modo_INICIAL(Tp1_07* handle);
static void react_modo_SETMODO1(Tp1_07* handle);
static void react_modo_SETMODO2(Tp1_07* handle);
static void react_modo_SETMODO3(Tp1_07* handle);
static void react_se_ales_OFF(Tp1_07* handle);
static void react_se_ales_ON(Tp1_07* handle);
static void react_MICRO_OFF(Tp1_07* handle);
static void react_MICRO_ON(Tp1_07* handle);
static void react_TECX__entry_Default(Tp1_07* handle);
static void react_main_region__entry_Default(Tp1_07* handle);
static void react_modo__entry_Default(Tp1_07* handle);
static void react_se_ales__entry_Default(Tp1_07* handle);
static void react_MICRO__entry_Default(Tp1_07* handle);
static void clearInEvents(Tp1_07* handle);
static void clearOutEvents(Tp1_07* handle);

const sc_integer TP1_07_TP1_07IFACE_ON = 0;
const sc_integer TP1_07_TP1_07IFACE_MODO1 = 3;
const sc_integer TP1_07_TP1_07IFACE_MODO2 = 4;
const sc_integer TP1_07_TP1_07IFACE_MODO3 = 5;
const sc_integer TP1_07_TP1_07IFACE_MODO = 1 << 0;
const sc_integer TP1_07_TP1_07IFACE_START = 1 << 1;
const sc_integer TP1_07_TP1_07IFACE_STOP = 1 << 1;
const sc_integer TP1_07_TP1_07IFACE_PUERTA = 1 << 2;

void tp1_07_init(Tp1_07* handle)
{
		sc_integer i;
	
		for (i = 0; i < TP1_07_MAX_ORTHOGONAL_STATES; ++i)
		{
			handle->stateConfVector[i] = Tp1_07_last_state;
		}
		
		
		handle->stateConfVectorPosition = 0;
	
		clearInEvents(handle);
		clearOutEvents(handle);
	
		/* Default init sequence for statechart tp1_07 */
		handle->internal.viTecla = 0;
		handle->internal.viModo = 3;
}

void tp1_07_enter(Tp1_07* handle)
{
	/* Default enter sequence for statechart tp1_07 */
	enseq_TECX_default(handle);
	enseq_main_region_default(handle);
	enseq_modo_default(handle);
	enseq_se_ales_default(handle);
	enseq_MICRO_default(handle);
}

void tp1_07_runCycle(Tp1_07* handle)
{
	clearOutEvents(handle);
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < TP1_07_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Tp1_07_TECX_DEBOUNCE:
		{
			react_TECX_DEBOUNCE(handle);
			break;
		}
		case Tp1_07_TECX_NO_OPRIMIDO:
		{
			react_TECX_NO_OPRIMIDO(handle);
			break;
		}
		case Tp1_07_TECX_OPRIMIDO:
		{
			react_TECX_OPRIMIDO(handle);
			break;
		}
		case Tp1_07_TECX_VALIDACION:
		{
			react_TECX_VALIDACION(handle);
			break;
		}
		case Tp1_07_main_region_ESPERA:
		{
			react_main_region_ESPERA(handle);
			break;
		}
		case Tp1_07_modo_INICIAL:
		{
			react_modo_INICIAL(handle);
			break;
		}
		case Tp1_07_modo_SETMODO1:
		{
			react_modo_SETMODO1(handle);
			break;
		}
		case Tp1_07_modo_SETMODO2:
		{
			react_modo_SETMODO2(handle);
			break;
		}
		case Tp1_07_modo_SETMODO3:
		{
			react_modo_SETMODO3(handle);
			break;
		}
		case Tp1_07_se_ales_OFF:
		{
			react_se_ales_OFF(handle);
			break;
		}
		case Tp1_07_se_ales_ON:
		{
			react_se_ales_ON(handle);
			break;
		}
		case Tp1_07_MICRO_OFF:
		{
			react_MICRO_OFF(handle);
			break;
		}
		case Tp1_07_MICRO_ON:
		{
			react_MICRO_ON(handle);
			break;
		}
		default:
			break;
		}
	}
	
	clearInEvents(handle);
}

void tp1_07_exit(Tp1_07* handle)
{
	/* Default exit sequence for statechart tp1_07 */
	exseq_TECX(handle);
	exseq_main_region(handle);
	exseq_modo(handle);
	exseq_se_ales(handle);
	exseq_MICRO(handle);
}

sc_boolean tp1_07_isActive(const Tp1_07* handle)
{
	sc_boolean result = bool_false;
	int i;
	
	for(i = 0; i < TP1_07_MAX_ORTHOGONAL_STATES; i++)
	{
		result = result || handle->stateConfVector[i] != Tp1_07_last_state;
	}
	
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean tp1_07_isFinal(const Tp1_07* handle)
{
   return bool_false;
}

void tp1_07_raiseTimeEvent(Tp1_07* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(Tp1_07TimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean tp1_07_isStateActive(const Tp1_07* handle, Tp1_07States state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Tp1_07_TECX_DEBOUNCE :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_07_TECX_DEBOUNCE] == Tp1_07_TECX_DEBOUNCE
			);
			break;
		case Tp1_07_TECX_NO_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_07_TECX_NO_OPRIMIDO] == Tp1_07_TECX_NO_OPRIMIDO
			);
			break;
		case Tp1_07_TECX_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_07_TECX_OPRIMIDO] == Tp1_07_TECX_OPRIMIDO
			);
			break;
		case Tp1_07_TECX_VALIDACION :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_07_TECX_VALIDACION] == Tp1_07_TECX_VALIDACION
			);
			break;
		case Tp1_07_main_region_ESPERA :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_07_MAIN_REGION_ESPERA] == Tp1_07_main_region_ESPERA
			);
			break;
		case Tp1_07_modo_INICIAL :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_07_MODO_INICIAL] == Tp1_07_modo_INICIAL
			);
			break;
		case Tp1_07_modo_SETMODO1 :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_07_MODO_SETMODO1] == Tp1_07_modo_SETMODO1
			);
			break;
		case Tp1_07_modo_SETMODO2 :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_07_MODO_SETMODO2] == Tp1_07_modo_SETMODO2
			);
			break;
		case Tp1_07_modo_SETMODO3 :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_07_MODO_SETMODO3] == Tp1_07_modo_SETMODO3
			);
			break;
		case Tp1_07_se_ales_OFF :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_07_SE_ALES_OFF] == Tp1_07_se_ales_OFF
			);
			break;
		case Tp1_07_se_ales_ON :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_07_SE_ALES_ON] == Tp1_07_se_ales_ON
			);
			break;
		case Tp1_07_MICRO_OFF :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_07_MICRO_OFF] == Tp1_07_MICRO_OFF
			);
			break;
		case Tp1_07_MICRO_ON :
			result = (sc_boolean) (handle->stateConfVector[SCVI_TP1_07_MICRO_ON] == Tp1_07_MICRO_ON
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

static void clearInEvents(Tp1_07* handle)
{
	handle->iface.evTECXNoOprimido_raised = bool_false;
	handle->iface.evTECXOprimido_raised = bool_false;
	handle->internal.siTECXOK_raised = bool_false;
	handle->internal.siStart_raised = bool_false;
	handle->internal.siStop_raised = bool_false;
	handle->internal.siPuerta_raised = bool_false;
	handle->internal.siCambiarModo_raised = bool_false;
	handle->internal.siBoton_raised = bool_false;
	handle->timeEvents.tp1_07_TECX_DEBOUNCE_tev0_raised = bool_false;
}

static void clearOutEvents(Tp1_07* handle)
{
}

void tp1_07Iface_raise_evTECXNoOprimido(Tp1_07* handle)
{
	handle->iface.evTECXNoOprimido_raised = bool_true;
}
void tp1_07Iface_raise_evTECXOprimido(Tp1_07* handle, sc_integer value)
{
	handle->iface.evTECXOprimido_value = value;
	handle->iface.evTECXOprimido_raised = bool_true;
}


const sc_integer tp1_07Iface_get_oN(const Tp1_07* handle)
{
	return TP1_07_TP1_07IFACE_ON;
}
const sc_integer tp1_07Iface_get_mODO1(const Tp1_07* handle)
{
	return TP1_07_TP1_07IFACE_MODO1;
}
const sc_integer tp1_07Iface_get_mODO2(const Tp1_07* handle)
{
	return TP1_07_TP1_07IFACE_MODO2;
}
const sc_integer tp1_07Iface_get_mODO3(const Tp1_07* handle)
{
	return TP1_07_TP1_07IFACE_MODO3;
}
const sc_integer tp1_07Iface_get_mODO(const Tp1_07* handle)
{
	return TP1_07_TP1_07IFACE_MODO;
}
const sc_integer tp1_07Iface_get_sTART(const Tp1_07* handle)
{
	return TP1_07_TP1_07IFACE_START;
}
const sc_integer tp1_07Iface_get_sTOP(const Tp1_07* handle)
{
	return TP1_07_TP1_07IFACE_STOP;
}
const sc_integer tp1_07Iface_get_pUERTA(const Tp1_07* handle)
{
	return TP1_07_TP1_07IFACE_PUERTA;
}

/* implementations of all internal functions */

static sc_boolean check_TECX_DEBOUNCE_tr0_tr0(const Tp1_07* handle)
{
	return handle->timeEvents.tp1_07_TECX_DEBOUNCE_tev0_raised;
}

static sc_boolean check_TECX_NO_OPRIMIDO_tr0_tr0(const Tp1_07* handle)
{
	return handle->iface.evTECXOprimido_raised;
}

static sc_boolean check_TECX_OPRIMIDO_tr0_tr0(const Tp1_07* handle)
{
	return handle->iface.evTECXNoOprimido_raised;
}

static sc_boolean check_TECX_VALIDACION_tr0_tr0(const Tp1_07* handle)
{
	return handle->iface.evTECXOprimido_raised;
}

static sc_boolean check_TECX_VALIDACION_tr1_tr1(const Tp1_07* handle)
{
	return handle->iface.evTECXNoOprimido_raised;
}

static sc_boolean check_main_region_ESPERA_tr0_tr0(const Tp1_07* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == TP1_07_TP1_07IFACE_MODO)) ? bool_true : bool_false;
}

static sc_boolean check_main_region_ESPERA_tr1_tr1(const Tp1_07* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == TP1_07_TP1_07IFACE_START)) ? bool_true : bool_false;
}

static sc_boolean check_main_region_ESPERA_tr2_tr2(const Tp1_07* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == TP1_07_TP1_07IFACE_PUERTA)) ? bool_true : bool_false;
}

static sc_boolean check_modo_INICIAL_tr0_tr0(const Tp1_07* handle)
{
	return handle->internal.siCambiarModo_raised;
}

static sc_boolean check_modo_SETMODO1_tr0_tr0(const Tp1_07* handle)
{
	return handle->internal.siCambiarModo_raised;
}

static sc_boolean check_modo_SETMODO2_tr0_tr0(const Tp1_07* handle)
{
	return handle->internal.siCambiarModo_raised;
}

static sc_boolean check_modo_SETMODO3_tr0_tr0(const Tp1_07* handle)
{
	return handle->internal.siCambiarModo_raised;
}

static sc_boolean check_se_ales_OFF_tr0_tr0(const Tp1_07* handle)
{
	return handle->internal.siBoton_raised;
}

static sc_boolean check_se_ales_ON_tr0_tr0(const Tp1_07* handle)
{
	return handle->internal.siBoton_raised;
}

static sc_boolean check_MICRO_OFF_tr0_tr0(const Tp1_07* handle)
{
	return handle->internal.siStart_raised;
}

static sc_boolean check_MICRO_ON_tr0_tr0(const Tp1_07* handle)
{
	return handle->internal.siStop_raised;
}

static sc_boolean check_MICRO_ON_tr1_tr1(const Tp1_07* handle)
{
	return handle->internal.siPuerta_raised;
}

static void effect_TECX_DEBOUNCE_tr0(Tp1_07* handle)
{
	exseq_TECX_DEBOUNCE(handle);
	enseq_TECX_VALIDACION_default(handle);
}

static void effect_TECX_NO_OPRIMIDO_tr0(Tp1_07* handle)
{
	exseq_TECX_NO_OPRIMIDO(handle);
	enseq_TECX_DEBOUNCE_default(handle);
}

static void effect_TECX_OPRIMIDO_tr0(Tp1_07* handle)
{
	exseq_TECX_OPRIMIDO(handle);
	enseq_TECX_NO_OPRIMIDO_default(handle);
}

static void effect_TECX_VALIDACION_tr0(Tp1_07* handle)
{
	exseq_TECX_VALIDACION(handle);
	enseq_TECX_OPRIMIDO_default(handle);
}

static void effect_TECX_VALIDACION_tr1(Tp1_07* handle)
{
	exseq_TECX_VALIDACION(handle);
	enseq_TECX_NO_OPRIMIDO_default(handle);
}

static void effect_main_region_ESPERA_tr0(Tp1_07* handle)
{
	exseq_main_region_ESPERA(handle);
	handle->internal.siCambiarModo_raised = bool_true;
	enseq_main_region_ESPERA_default(handle);
}

static void effect_main_region_ESPERA_tr1(Tp1_07* handle)
{
	exseq_main_region_ESPERA(handle);
	handle->internal.siBoton_raised = bool_true;
	enseq_main_region_ESPERA_default(handle);
}

static void effect_main_region_ESPERA_tr2(Tp1_07* handle)
{
	exseq_main_region_ESPERA(handle);
	handle->internal.siPuerta_raised = bool_true;
	enseq_main_region_ESPERA_default(handle);
}

static void effect_modo_INICIAL_tr0(Tp1_07* handle)
{
	exseq_modo_INICIAL(handle);
	enseq_modo_SETMODO1_default(handle);
}

static void effect_modo_SETMODO1_tr0(Tp1_07* handle)
{
	exseq_modo_SETMODO1(handle);
	enseq_modo_SETMODO2_default(handle);
}

static void effect_modo_SETMODO2_tr0(Tp1_07* handle)
{
	exseq_modo_SETMODO2(handle);
	enseq_modo_SETMODO3_default(handle);
}

static void effect_modo_SETMODO3_tr0(Tp1_07* handle)
{
	exseq_modo_SETMODO3(handle);
	enseq_modo_SETMODO1_default(handle);
}

static void effect_se_ales_OFF_tr0(Tp1_07* handle)
{
	exseq_se_ales_OFF(handle);
	handle->internal.siStart_raised = bool_true;
	enseq_se_ales_ON_default(handle);
}

static void effect_se_ales_ON_tr0(Tp1_07* handle)
{
	exseq_se_ales_ON(handle);
	handle->internal.siStop_raised = bool_true;
	enseq_se_ales_OFF_default(handle);
}

static void effect_MICRO_OFF_tr0(Tp1_07* handle)
{
	exseq_MICRO_OFF(handle);
	enseq_MICRO_ON_default(handle);
}

static void effect_MICRO_ON_tr0(Tp1_07* handle)
{
	exseq_MICRO_ON(handle);
	enseq_MICRO_OFF_default(handle);
}

static void effect_MICRO_ON_tr1(Tp1_07* handle)
{
	exseq_MICRO_ON(handle);
	enseq_MICRO_OFF_default(handle);
}

/* Entry action for state 'DEBOUNCE'. */
static void enact_TECX_DEBOUNCE(Tp1_07* handle)
{
	/* Entry action for state 'DEBOUNCE'. */
	tp1_07_setTimer(handle, (sc_eventid) &(handle->timeEvents.tp1_07_TECX_DEBOUNCE_tev0_raised) , 100, bool_false);
}

/* Entry action for state 'OPRIMIDO'. */
static void enact_TECX_OPRIMIDO(Tp1_07* handle)
{
	/* Entry action for state 'OPRIMIDO'. */
	handle->internal.siTECXOK_raised = bool_true;
	handle->internal.viTecla = handle->iface.evTECXOprimido_value;
}

/* Entry action for state 'INICIAL'. */
static void enact_modo_INICIAL(Tp1_07* handle)
{
	/* Entry action for state 'INICIAL'. */
	tp1_07Iface_opSETMODO(handle, handle->internal.viModo);
}

/* Entry action for state 'SETMODO1'. */
static void enact_modo_SETMODO1(Tp1_07* handle)
{
	/* Entry action for state 'SETMODO1'. */
	handle->internal.viModo = TP1_07_TP1_07IFACE_MODO1;
	tp1_07Iface_opSETMODO(handle, handle->internal.viModo);
}

/* Entry action for state 'SETMODO2'. */
static void enact_modo_SETMODO2(Tp1_07* handle)
{
	/* Entry action for state 'SETMODO2'. */
	handle->internal.viModo = TP1_07_TP1_07IFACE_MODO2;
	tp1_07Iface_opSETMODO(handle, handle->internal.viModo);
}

/* Entry action for state 'SETMODO3'. */
static void enact_modo_SETMODO3(Tp1_07* handle)
{
	/* Entry action for state 'SETMODO3'. */
	handle->internal.viModo = TP1_07_TP1_07IFACE_MODO3;
	tp1_07Iface_opSETMODO(handle, handle->internal.viModo);
}

/* Entry action for state 'OFF'. */
static void enact_se_ales_OFF(Tp1_07* handle)
{
	/* Entry action for state 'OFF'. */
	handle->internal.siStop_raised = bool_true;
}

/* Entry action for state 'OFF'. */
static void enact_MICRO_OFF(Tp1_07* handle)
{
	/* Entry action for state 'OFF'. */
	tp1_07Iface_opMICROOFF(handle, TP1_07_TP1_07IFACE_ON);
}

/* Entry action for state 'ON'. */
static void enact_MICRO_ON(Tp1_07* handle)
{
	/* Entry action for state 'ON'. */
	tp1_07Iface_opMICROON(handle, TP1_07_TP1_07IFACE_ON);
}

/* Exit action for state 'DEBOUNCE'. */
static void exact_TECX_DEBOUNCE(Tp1_07* handle)
{
	/* Exit action for state 'DEBOUNCE'. */
	tp1_07_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.tp1_07_TECX_DEBOUNCE_tev0_raised) );		
}

/* 'default' enter sequence for state DEBOUNCE */
static void enseq_TECX_DEBOUNCE_default(Tp1_07* handle)
{
	/* 'default' enter sequence for state DEBOUNCE */
	enact_TECX_DEBOUNCE(handle);
	handle->stateConfVector[0] = Tp1_07_TECX_DEBOUNCE;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state NO_OPRIMIDO */
static void enseq_TECX_NO_OPRIMIDO_default(Tp1_07* handle)
{
	/* 'default' enter sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Tp1_07_TECX_NO_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state OPRIMIDO */
static void enseq_TECX_OPRIMIDO_default(Tp1_07* handle)
{
	/* 'default' enter sequence for state OPRIMIDO */
	enact_TECX_OPRIMIDO(handle);
	handle->stateConfVector[0] = Tp1_07_TECX_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state VALIDACION */
static void enseq_TECX_VALIDACION_default(Tp1_07* handle)
{
	/* 'default' enter sequence for state VALIDACION */
	handle->stateConfVector[0] = Tp1_07_TECX_VALIDACION;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state ESPERA */
static void enseq_main_region_ESPERA_default(Tp1_07* handle)
{
	/* 'default' enter sequence for state ESPERA */
	handle->stateConfVector[1] = Tp1_07_main_region_ESPERA;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state INICIAL */
static void enseq_modo_INICIAL_default(Tp1_07* handle)
{
	/* 'default' enter sequence for state INICIAL */
	enact_modo_INICIAL(handle);
	handle->stateConfVector[2] = Tp1_07_modo_INICIAL;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state SETMODO1 */
static void enseq_modo_SETMODO1_default(Tp1_07* handle)
{
	/* 'default' enter sequence for state SETMODO1 */
	enact_modo_SETMODO1(handle);
	handle->stateConfVector[2] = Tp1_07_modo_SETMODO1;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state SETMODO2 */
static void enseq_modo_SETMODO2_default(Tp1_07* handle)
{
	/* 'default' enter sequence for state SETMODO2 */
	enact_modo_SETMODO2(handle);
	handle->stateConfVector[2] = Tp1_07_modo_SETMODO2;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state SETMODO3 */
static void enseq_modo_SETMODO3_default(Tp1_07* handle)
{
	/* 'default' enter sequence for state SETMODO3 */
	enact_modo_SETMODO3(handle);
	handle->stateConfVector[2] = Tp1_07_modo_SETMODO3;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state OFF */
static void enseq_se_ales_OFF_default(Tp1_07* handle)
{
	/* 'default' enter sequence for state OFF */
	enact_se_ales_OFF(handle);
	handle->stateConfVector[3] = Tp1_07_se_ales_OFF;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state ON */
static void enseq_se_ales_ON_default(Tp1_07* handle)
{
	/* 'default' enter sequence for state ON */
	handle->stateConfVector[3] = Tp1_07_se_ales_ON;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state OFF */
static void enseq_MICRO_OFF_default(Tp1_07* handle)
{
	/* 'default' enter sequence for state OFF */
	enact_MICRO_OFF(handle);
	handle->stateConfVector[4] = Tp1_07_MICRO_OFF;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for state ON */
static void enseq_MICRO_ON_default(Tp1_07* handle)
{
	/* 'default' enter sequence for state ON */
	enact_MICRO_ON(handle);
	handle->stateConfVector[4] = Tp1_07_MICRO_ON;
	handle->stateConfVectorPosition = 4;
}

/* 'default' enter sequence for region TECX */
static void enseq_TECX_default(Tp1_07* handle)
{
	/* 'default' enter sequence for region TECX */
	react_TECX__entry_Default(handle);
}

/* 'default' enter sequence for region main region */
static void enseq_main_region_default(Tp1_07* handle)
{
	/* 'default' enter sequence for region main region */
	react_main_region__entry_Default(handle);
}

/* 'default' enter sequence for region modo */
static void enseq_modo_default(Tp1_07* handle)
{
	/* 'default' enter sequence for region modo */
	react_modo__entry_Default(handle);
}

/* 'default' enter sequence for region señales */
static void enseq_se_ales_default(Tp1_07* handle)
{
	/* 'default' enter sequence for region señales */
	react_se_ales__entry_Default(handle);
}

/* 'default' enter sequence for region MICRO */
static void enseq_MICRO_default(Tp1_07* handle)
{
	/* 'default' enter sequence for region MICRO */
	react_MICRO__entry_Default(handle);
}

/* Default exit sequence for state DEBOUNCE */
static void exseq_TECX_DEBOUNCE(Tp1_07* handle)
{
	/* Default exit sequence for state DEBOUNCE */
	handle->stateConfVector[0] = Tp1_07_last_state;
	handle->stateConfVectorPosition = 0;
	exact_TECX_DEBOUNCE(handle);
}

/* Default exit sequence for state NO_OPRIMIDO */
static void exseq_TECX_NO_OPRIMIDO(Tp1_07* handle)
{
	/* Default exit sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Tp1_07_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state OPRIMIDO */
static void exseq_TECX_OPRIMIDO(Tp1_07* handle)
{
	/* Default exit sequence for state OPRIMIDO */
	handle->stateConfVector[0] = Tp1_07_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state VALIDACION */
static void exseq_TECX_VALIDACION(Tp1_07* handle)
{
	/* Default exit sequence for state VALIDACION */
	handle->stateConfVector[0] = Tp1_07_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state ESPERA */
static void exseq_main_region_ESPERA(Tp1_07* handle)
{
	/* Default exit sequence for state ESPERA */
	handle->stateConfVector[1] = Tp1_07_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state INICIAL */
static void exseq_modo_INICIAL(Tp1_07* handle)
{
	/* Default exit sequence for state INICIAL */
	handle->stateConfVector[2] = Tp1_07_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state SETMODO1 */
static void exseq_modo_SETMODO1(Tp1_07* handle)
{
	/* Default exit sequence for state SETMODO1 */
	handle->stateConfVector[2] = Tp1_07_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state SETMODO2 */
static void exseq_modo_SETMODO2(Tp1_07* handle)
{
	/* Default exit sequence for state SETMODO2 */
	handle->stateConfVector[2] = Tp1_07_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state SETMODO3 */
static void exseq_modo_SETMODO3(Tp1_07* handle)
{
	/* Default exit sequence for state SETMODO3 */
	handle->stateConfVector[2] = Tp1_07_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state OFF */
static void exseq_se_ales_OFF(Tp1_07* handle)
{
	/* Default exit sequence for state OFF */
	handle->stateConfVector[3] = Tp1_07_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state ON */
static void exseq_se_ales_ON(Tp1_07* handle)
{
	/* Default exit sequence for state ON */
	handle->stateConfVector[3] = Tp1_07_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state OFF */
static void exseq_MICRO_OFF(Tp1_07* handle)
{
	/* Default exit sequence for state OFF */
	handle->stateConfVector[4] = Tp1_07_last_state;
	handle->stateConfVectorPosition = 4;
}

/* Default exit sequence for state ON */
static void exseq_MICRO_ON(Tp1_07* handle)
{
	/* Default exit sequence for state ON */
	handle->stateConfVector[4] = Tp1_07_last_state;
	handle->stateConfVectorPosition = 4;
}

/* Default exit sequence for region TECX */
static void exseq_TECX(Tp1_07* handle)
{
	/* Default exit sequence for region TECX */
	/* Handle exit of all possible states (of tp1_07.TECX) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Tp1_07_TECX_DEBOUNCE :
		{
			exseq_TECX_DEBOUNCE(handle);
			break;
		}
		case Tp1_07_TECX_NO_OPRIMIDO :
		{
			exseq_TECX_NO_OPRIMIDO(handle);
			break;
		}
		case Tp1_07_TECX_OPRIMIDO :
		{
			exseq_TECX_OPRIMIDO(handle);
			break;
		}
		case Tp1_07_TECX_VALIDACION :
		{
			exseq_TECX_VALIDACION(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region main region */
static void exseq_main_region(Tp1_07* handle)
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of tp1_07.main_region) at position 1... */
	switch(handle->stateConfVector[ 1 ])
	{
		case Tp1_07_main_region_ESPERA :
		{
			exseq_main_region_ESPERA(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region modo */
static void exseq_modo(Tp1_07* handle)
{
	/* Default exit sequence for region modo */
	/* Handle exit of all possible states (of tp1_07.modo) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case Tp1_07_modo_INICIAL :
		{
			exseq_modo_INICIAL(handle);
			break;
		}
		case Tp1_07_modo_SETMODO1 :
		{
			exseq_modo_SETMODO1(handle);
			break;
		}
		case Tp1_07_modo_SETMODO2 :
		{
			exseq_modo_SETMODO2(handle);
			break;
		}
		case Tp1_07_modo_SETMODO3 :
		{
			exseq_modo_SETMODO3(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region señales */
static void exseq_se_ales(Tp1_07* handle)
{
	/* Default exit sequence for region señales */
	/* Handle exit of all possible states (of tp1_07.señales) at position 3... */
	switch(handle->stateConfVector[ 3 ])
	{
		case Tp1_07_se_ales_OFF :
		{
			exseq_se_ales_OFF(handle);
			break;
		}
		case Tp1_07_se_ales_ON :
		{
			exseq_se_ales_ON(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region MICRO */
static void exseq_MICRO(Tp1_07* handle)
{
	/* Default exit sequence for region MICRO */
	/* Handle exit of all possible states (of tp1_07.MICRO) at position 4... */
	switch(handle->stateConfVector[ 4 ])
	{
		case Tp1_07_MICRO_OFF :
		{
			exseq_MICRO_OFF(handle);
			break;
		}
		case Tp1_07_MICRO_ON :
		{
			exseq_MICRO_ON(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state DEBOUNCE. */
static void react_TECX_DEBOUNCE(Tp1_07* handle)
{
	/* The reactions of state DEBOUNCE. */
	if (check_TECX_DEBOUNCE_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_DEBOUNCE_tr0(handle);
	} 
}

/* The reactions of state NO_OPRIMIDO. */
static void react_TECX_NO_OPRIMIDO(Tp1_07* handle)
{
	/* The reactions of state NO_OPRIMIDO. */
	if (check_TECX_NO_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_NO_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state OPRIMIDO. */
static void react_TECX_OPRIMIDO(Tp1_07* handle)
{
	/* The reactions of state OPRIMIDO. */
	if (check_TECX_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		effect_TECX_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state VALIDACION. */
static void react_TECX_VALIDACION(Tp1_07* handle)
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
static void react_main_region_ESPERA(Tp1_07* handle)
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

/* The reactions of state INICIAL. */
static void react_modo_INICIAL(Tp1_07* handle)
{
	/* The reactions of state INICIAL. */
	if (check_modo_INICIAL_tr0_tr0(handle) == bool_true)
	{ 
		effect_modo_INICIAL_tr0(handle);
	} 
}

/* The reactions of state SETMODO1. */
static void react_modo_SETMODO1(Tp1_07* handle)
{
	/* The reactions of state SETMODO1. */
	if (check_modo_SETMODO1_tr0_tr0(handle) == bool_true)
	{ 
		effect_modo_SETMODO1_tr0(handle);
	} 
}

/* The reactions of state SETMODO2. */
static void react_modo_SETMODO2(Tp1_07* handle)
{
	/* The reactions of state SETMODO2. */
	if (check_modo_SETMODO2_tr0_tr0(handle) == bool_true)
	{ 
		effect_modo_SETMODO2_tr0(handle);
	} 
}

/* The reactions of state SETMODO3. */
static void react_modo_SETMODO3(Tp1_07* handle)
{
	/* The reactions of state SETMODO3. */
	if (check_modo_SETMODO3_tr0_tr0(handle) == bool_true)
	{ 
		effect_modo_SETMODO3_tr0(handle);
	} 
}

/* The reactions of state OFF. */
static void react_se_ales_OFF(Tp1_07* handle)
{
	/* The reactions of state OFF. */
	if (check_se_ales_OFF_tr0_tr0(handle) == bool_true)
	{ 
		effect_se_ales_OFF_tr0(handle);
	} 
}

/* The reactions of state ON. */
static void react_se_ales_ON(Tp1_07* handle)
{
	/* The reactions of state ON. */
	if (check_se_ales_ON_tr0_tr0(handle) == bool_true)
	{ 
		effect_se_ales_ON_tr0(handle);
	} 
}

/* The reactions of state OFF. */
static void react_MICRO_OFF(Tp1_07* handle)
{
	/* The reactions of state OFF. */
	if (check_MICRO_OFF_tr0_tr0(handle) == bool_true)
	{ 
		effect_MICRO_OFF_tr0(handle);
	} 
}

/* The reactions of state ON. */
static void react_MICRO_ON(Tp1_07* handle)
{
	/* The reactions of state ON. */
	if (check_MICRO_ON_tr0_tr0(handle) == bool_true)
	{ 
		effect_MICRO_ON_tr0(handle);
	}  else
	{
		if (check_MICRO_ON_tr1_tr1(handle) == bool_true)
		{ 
			effect_MICRO_ON_tr1(handle);
		} 
	}
}

/* Default react sequence for initial entry  */
static void react_TECX__entry_Default(Tp1_07* handle)
{
	/* Default react sequence for initial entry  */
	enseq_TECX_NO_OPRIMIDO_default(handle);
}

/* Default react sequence for initial entry  */
static void react_main_region__entry_Default(Tp1_07* handle)
{
	/* Default react sequence for initial entry  */
	enseq_main_region_ESPERA_default(handle);
}

/* Default react sequence for initial entry  */
static void react_modo__entry_Default(Tp1_07* handle)
{
	/* Default react sequence for initial entry  */
	enseq_modo_INICIAL_default(handle);
}

/* Default react sequence for initial entry  */
static void react_se_ales__entry_Default(Tp1_07* handle)
{
	/* Default react sequence for initial entry  */
	enseq_se_ales_OFF_default(handle);
}

/* Default react sequence for initial entry  */
static void react_MICRO__entry_Default(Tp1_07* handle)
{
	/* Default react sequence for initial entry  */
	enseq_MICRO_OFF_default(handle);
}


