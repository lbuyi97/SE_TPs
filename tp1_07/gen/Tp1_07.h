
#ifndef TP1_07_H_
#define TP1_07_H_

#include "..\inc\sc_types.h"

#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'tp1_07'.
*/

/*! Define dimension of the state configuration vector for orthogonal states. */
#define TP1_07_MAX_ORTHOGONAL_STATES 5

/*! Define maximum number of time events that can be active at once */
#define TP1_07_MAX_PARALLEL_TIME_EVENTS 1

/*! Define indices of states in the StateConfVector */
#define SCVI_TP1_07_TECX_DEBOUNCE 0
#define SCVI_TP1_07_TECX_NO_OPRIMIDO 0
#define SCVI_TP1_07_TECX_OPRIMIDO 0
#define SCVI_TP1_07_TECX_VALIDACION 0
#define SCVI_TP1_07_MAIN_REGION_ESPERA 1
#define SCVI_TP1_07_MODO_INICIAL 2
#define SCVI_TP1_07_MODO_SETMODO1 2
#define SCVI_TP1_07_MODO_SETMODO2 2
#define SCVI_TP1_07_MODO_SETMODO3 2
#define SCVI_TP1_07_SE_ALES_OFF 3
#define SCVI_TP1_07_SE_ALES_ON 3
#define SCVI_TP1_07_MICRO_OFF 4
#define SCVI_TP1_07_MICRO_ON 4

/*! Enumeration of all states */ 
typedef enum
{
	Tp1_07_last_state,
	Tp1_07_TECX_DEBOUNCE,
	Tp1_07_TECX_NO_OPRIMIDO,
	Tp1_07_TECX_OPRIMIDO,
	Tp1_07_TECX_VALIDACION,
	Tp1_07_main_region_ESPERA,
	Tp1_07_modo_INICIAL,
	Tp1_07_modo_SETMODO1,
	Tp1_07_modo_SETMODO2,
	Tp1_07_modo_SETMODO3,
	Tp1_07_se_ales_OFF,
	Tp1_07_se_ales_ON,
	Tp1_07_MICRO_OFF,
	Tp1_07_MICRO_ON
} Tp1_07States;

/*! Type definition of the data structure for the Tp1_07Iface interface scope. */
typedef struct
{
	sc_boolean evTECXNoOprimido_raised;
	sc_boolean evTECXOprimido_raised;
	sc_integer evTECXOprimido_value;
} Tp1_07Iface;


/* Declaration of constants for scope Tp1_07Iface. */
extern const sc_integer TP1_07_TP1_07IFACE_ON;
extern const sc_integer TP1_07_TP1_07IFACE_MODO1;
extern const sc_integer TP1_07_TP1_07IFACE_MODO2;
extern const sc_integer TP1_07_TP1_07IFACE_MODO3;
extern const sc_integer TP1_07_TP1_07IFACE_MODO;
extern const sc_integer TP1_07_TP1_07IFACE_START;
extern const sc_integer TP1_07_TP1_07IFACE_STOP;
extern const sc_integer TP1_07_TP1_07IFACE_PUERTA;


/*! Type definition of the data structure for the Tp1_07Internal interface scope. */
typedef struct
{
	sc_boolean siTECXOK_raised;
	sc_boolean siStart_raised;
	sc_boolean siStop_raised;
	sc_boolean siPuerta_raised;
	sc_boolean siCambiarModo_raised;
	sc_boolean siBoton_raised;
	sc_integer viTecla;
	sc_integer viModo;
} Tp1_07Internal;



/*! Type definition of the data structure for the Tp1_07TimeEvents interface scope. */
typedef struct
{
	sc_boolean tp1_07_TECX_DEBOUNCE_tev0_raised;
} Tp1_07TimeEvents;




/*! 
 * Type definition of the data structure for the Tp1_07 state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	Tp1_07States stateConfVector[TP1_07_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	Tp1_07Iface iface;
	Tp1_07Internal internal;
	Tp1_07TimeEvents timeEvents;
} Tp1_07;



/*! Initializes the Tp1_07 state machine data structures. Must be called before first usage.*/
extern void tp1_07_init(Tp1_07* handle);

/*! Activates the state machine */
extern void tp1_07_enter(Tp1_07* handle);

/*! Deactivates the state machine */
extern void tp1_07_exit(Tp1_07* handle);

/*! Performs a 'run to completion' step. */
extern void tp1_07_runCycle(Tp1_07* handle);

/*! Raises a time event. */
extern void tp1_07_raiseTimeEvent(Tp1_07* handle, sc_eventid evid);

/*! Raises the in event 'evTECXNoOprimido' that is defined in the default interface scope. */ 
extern void tp1_07Iface_raise_evTECXNoOprimido(Tp1_07* handle);

/*! Raises the in event 'evTECXOprimido' that is defined in the default interface scope. */ 
extern void tp1_07Iface_raise_evTECXOprimido(Tp1_07* handle, sc_integer value);

/*! Gets the value of the variable 'ON' that is defined in the default interface scope. */ 
extern const sc_integer tp1_07Iface_get_oN(const Tp1_07* handle);
/*! Gets the value of the variable 'MODO1' that is defined in the default interface scope. */ 
extern const sc_integer tp1_07Iface_get_mODO1(const Tp1_07* handle);
/*! Gets the value of the variable 'MODO2' that is defined in the default interface scope. */ 
extern const sc_integer tp1_07Iface_get_mODO2(const Tp1_07* handle);
/*! Gets the value of the variable 'MODO3' that is defined in the default interface scope. */ 
extern const sc_integer tp1_07Iface_get_mODO3(const Tp1_07* handle);
/*! Gets the value of the variable 'MODO' that is defined in the default interface scope. */ 
extern const sc_integer tp1_07Iface_get_mODO(const Tp1_07* handle);
/*! Gets the value of the variable 'START' that is defined in the default interface scope. */ 
extern const sc_integer tp1_07Iface_get_sTART(const Tp1_07* handle);
/*! Gets the value of the variable 'STOP' that is defined in the default interface scope. */ 
extern const sc_integer tp1_07Iface_get_sTOP(const Tp1_07* handle);
/*! Gets the value of the variable 'PUERTA' that is defined in the default interface scope. */ 
extern const sc_integer tp1_07Iface_get_pUERTA(const Tp1_07* handle);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean tp1_07_isActive(const Tp1_07* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean tp1_07_isFinal(const Tp1_07* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean tp1_07_isStateActive(const Tp1_07* handle, Tp1_07States state);


#ifdef __cplusplus
}
#endif 

#endif /* TP1_07_H_ */
