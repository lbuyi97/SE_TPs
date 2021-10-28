
#ifndef TP1_08_H_
#define TP1_08_H_

#include "..\inc\sc_types.h"

#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'tp1_08'.
*/

/*! Define dimension of the state configuration vector for orthogonal states. */
#define TP1_08_MAX_ORTHOGONAL_STATES 3

/*! Define maximum number of time events that can be active at once */
#define TP1_08_MAX_PARALLEL_TIME_EVENTS 1

/*! Define indices of states in the StateConfVector */
#define SCVI_TP1_08_TECX_DEBOUNCE 0
#define SCVI_TP1_08_TECX_NO_OPRIMIDO 0
#define SCVI_TP1_08_TECX_OPRIMIDO 0
#define SCVI_TP1_08_TECX_VALIDACION 0
#define SCVI_TP1_08_MAIN_REGION_ESPERA 1
#define SCVI_TP1_08_MODO_INICIAL 2
#define SCVI_TP1_08_MODO_SETMODO1 2
#define SCVI_TP1_08_MODO_SETMODO2 2
#define SCVI_TP1_08_MODO_SETMODO3 2

/*! Enumeration of all states */ 
typedef enum
{
	Tp1_08_last_state,
	Tp1_08_TECX_DEBOUNCE,
	Tp1_08_TECX_NO_OPRIMIDO,
	Tp1_08_TECX_OPRIMIDO,
	Tp1_08_TECX_VALIDACION,
	Tp1_08_main_region_ESPERA,
	Tp1_08_modo_INICIAL,
	Tp1_08_modo_SETMODO1,
	Tp1_08_modo_SETMODO2,
	Tp1_08_modo_SETMODO3
} Tp1_08States;

/*! Type definition of the data structure for the Tp1_08Iface interface scope. */
typedef struct
{
	sc_boolean evTECXNoOprimido_raised;
	sc_boolean evTECXOprimido_raised;
	sc_integer evTECXOprimido_value;
} Tp1_08Iface;


/* Declaration of constants for scope Tp1_08Iface. */
extern const sc_integer TP1_08_TP1_08IFACE_ON;
extern const sc_integer TP1_08_TP1_08IFACE_MODO1;
extern const sc_integer TP1_08_TP1_08IFACE_MODO2;
extern const sc_integer TP1_08_TP1_08IFACE_MODO3;
extern const sc_integer TP1_08_TP1_08IFACE_MODO;
extern const sc_integer TP1_08_TP1_08IFACE_START;
extern const sc_integer TP1_08_TP1_08IFACE_STOP;
extern const sc_integer TP1_08_TP1_08IFACE_PUERTA;


/*! Type definition of the data structure for the Tp1_08Internal interface scope. */
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
} Tp1_08Internal;



/*! Type definition of the data structure for the Tp1_08TimeEvents interface scope. */
typedef struct
{
	sc_boolean tp1_08_TECX_DEBOUNCE_tev0_raised;
} Tp1_08TimeEvents;




/*! 
 * Type definition of the data structure for the Tp1_08 state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	Tp1_08States stateConfVector[TP1_08_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	Tp1_08Iface iface;
	Tp1_08Internal internal;
	Tp1_08TimeEvents timeEvents;
} Tp1_08;



/*! Initializes the Tp1_08 state machine data structures. Must be called before first usage.*/
extern void tp1_08_init(Tp1_08* handle);

/*! Activates the state machine */
extern void tp1_08_enter(Tp1_08* handle);

/*! Deactivates the state machine */
extern void tp1_08_exit(Tp1_08* handle);

/*! Performs a 'run to completion' step. */
extern void tp1_08_runCycle(Tp1_08* handle);

/*! Raises a time event. */
extern void tp1_08_raiseTimeEvent(Tp1_08* handle, sc_eventid evid);

/*! Raises the in event 'evTECXNoOprimido' that is defined in the default interface scope. */ 
extern void tp1_08Iface_raise_evTECXNoOprimido(Tp1_08* handle);

/*! Raises the in event 'evTECXOprimido' that is defined in the default interface scope. */ 
extern void tp1_08Iface_raise_evTECXOprimido(Tp1_08* handle, sc_integer value);

/*! Gets the value of the variable 'ON' that is defined in the default interface scope. */ 
extern const sc_integer tp1_08Iface_get_oN(const Tp1_08* handle);
/*! Gets the value of the variable 'MODO1' that is defined in the default interface scope. */ 
extern const sc_integer tp1_08Iface_get_mODO1(const Tp1_08* handle);
/*! Gets the value of the variable 'MODO2' that is defined in the default interface scope. */ 
extern const sc_integer tp1_08Iface_get_mODO2(const Tp1_08* handle);
/*! Gets the value of the variable 'MODO3' that is defined in the default interface scope. */ 
extern const sc_integer tp1_08Iface_get_mODO3(const Tp1_08* handle);
/*! Gets the value of the variable 'MODO' that is defined in the default interface scope. */ 
extern const sc_integer tp1_08Iface_get_mODO(const Tp1_08* handle);
/*! Gets the value of the variable 'START' that is defined in the default interface scope. */ 
extern const sc_integer tp1_08Iface_get_sTART(const Tp1_08* handle);
/*! Gets the value of the variable 'STOP' that is defined in the default interface scope. */ 
extern const sc_integer tp1_08Iface_get_sTOP(const Tp1_08* handle);
/*! Gets the value of the variable 'PUERTA' that is defined in the default interface scope. */ 
extern const sc_integer tp1_08Iface_get_pUERTA(const Tp1_08* handle);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean tp1_08_isActive(const Tp1_08* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean tp1_08_isFinal(const Tp1_08* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean tp1_08_isStateActive(const Tp1_08* handle, Tp1_08States state);


#ifdef __cplusplus
}
#endif 

#endif /* TP1_08_H_ */
