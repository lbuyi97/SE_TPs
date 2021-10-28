
#ifndef TP1_04_H_
#define TP1_04_H_

#include "..\inc\sc_types.h"

#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'tp1_04'.
*/

/*! Define dimension of the state configuration vector for orthogonal states. */
#define TP1_04_MAX_ORTHOGONAL_STATES 3

/*! Define maximum number of time events that can be active at once */
#define TP1_04_MAX_PARALLEL_TIME_EVENTS 2

/*! Define indices of states in the StateConfVector */
#define SCVI_TP1_04_TECX_DEBOUNCE 0
#define SCVI_TP1_04_TECX_NO_OPRIMIDO 0
#define SCVI_TP1_04_TECX_OPRIMIDO 0
#define SCVI_TP1_04_TECX_VALIDACION 0
#define SCVI_TP1_04_MAIN_REGION_ESPERA 1
#define SCVI_TP1_04_PUERTA_ABRIR 2
#define SCVI_TP1_04_PUERTA_ABRIR_ABRIR_STOP 2
#define SCVI_TP1_04_PUERTA_ABRIR_ABRIR_PRENDER_MOTOR_DOWN 2
#define SCVI_TP1_04_PUERTA_ABRIR_ABRIR_ESPERA 2
#define SCVI_TP1_04_PUERTA_REPOSO 2
#define SCVI_TP1_04_PUERTA_CERRAR 2
#define SCVI_TP1_04_PUERTA_CERRAR_CERRAR_PRENDER_MOTOR_UP 2
#define SCVI_TP1_04_PUERTA_CERRAR_CERRAR_STOP 2

/*! Enumeration of all states */ 
typedef enum
{
	Tp1_04_last_state,
	Tp1_04_TECX_DEBOUNCE,
	Tp1_04_TECX_NO_OPRIMIDO,
	Tp1_04_TECX_OPRIMIDO,
	Tp1_04_TECX_VALIDACION,
	Tp1_04_main_region_ESPERA,
	Tp1_04_PUERTA_ABRIR,
	Tp1_04_PUERTA_ABRIR_abrir_STOP,
	Tp1_04_PUERTA_ABRIR_abrir_PRENDER_MOTOR_DOWN,
	Tp1_04_PUERTA_ABRIR_abrir_ESPERA,
	Tp1_04_PUERTA_REPOSO,
	Tp1_04_PUERTA_CERRAR,
	Tp1_04_PUERTA_CERRAR_cerrar_PRENDER_MOTOR_UP,
	Tp1_04_PUERTA_CERRAR_cerrar_STOP
} Tp1_04States;

/*! Type definition of the data structure for the Tp1_04Iface interface scope. */
typedef struct
{
	sc_boolean evTECXNoOprimido_raised;
	sc_boolean evTECXOprimido_raised;
	sc_integer evTECXOprimido_value;
} Tp1_04Iface;


/* Declaration of constants for scope Tp1_04Iface. */
extern const sc_integer TP1_04_TP1_04IFACE_MOTORUP;
extern const sc_integer TP1_04_TP1_04IFACE_MOTORDOWN;
extern const sc_boolean TP1_04_TP1_04IFACE_MOTOR_ON;
extern const sc_boolean TP1_04_TP1_04IFACE_MOTOR_OFF;
extern const sc_integer TP1_04_TP1_04IFACE_SENSP;
extern const sc_integer TP1_04_TP1_04IFACE_FCARRI;
extern const sc_integer TP1_04_TP1_04IFACE_FCARRF;


/*! Type definition of the data structure for the Tp1_04Internal interface scope. */
typedef struct
{
	sc_boolean siTECXOK_raised;
	sc_boolean siFinCarreraIni_raised;
	sc_boolean siFinCarreraFin_raised;
	sc_boolean siMotorUp_raised;
	sc_boolean siMotorDown_raised;
	sc_boolean siMotorOff_raised;
	sc_integer viTecla;
} Tp1_04Internal;



/*! Type definition of the data structure for the Tp1_04TimeEvents interface scope. */
typedef struct
{
	sc_boolean tp1_04_TECX_DEBOUNCE_tev0_raised;
	sc_boolean tp1_04_PUERTA_ABRIR_abrir_STOP_tev0_raised;
	sc_boolean tp1_04_PUERTA_ABRIR_abrir_ESPERA_tev0_raised;
	sc_boolean tp1_04_PUERTA_CERRAR_cerrar_STOP_tev0_raised;
} Tp1_04TimeEvents;




/*! 
 * Type definition of the data structure for the Tp1_04 state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	Tp1_04States stateConfVector[TP1_04_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	Tp1_04Iface iface;
	Tp1_04Internal internal;
	Tp1_04TimeEvents timeEvents;
} Tp1_04;



/*! Initializes the Tp1_04 state machine data structures. Must be called before first usage.*/
extern void tp1_04_init(Tp1_04* handle);

/*! Activates the state machine */
extern void tp1_04_enter(Tp1_04* handle);

/*! Deactivates the state machine */
extern void tp1_04_exit(Tp1_04* handle);

/*! Performs a 'run to completion' step. */
extern void tp1_04_runCycle(Tp1_04* handle);

/*! Raises a time event. */
extern void tp1_04_raiseTimeEvent(Tp1_04* handle, sc_eventid evid);

/*! Raises the in event 'evTECXNoOprimido' that is defined in the default interface scope. */ 
extern void tp1_04Iface_raise_evTECXNoOprimido(Tp1_04* handle);

/*! Raises the in event 'evTECXOprimido' that is defined in the default interface scope. */ 
extern void tp1_04Iface_raise_evTECXOprimido(Tp1_04* handle, sc_integer value);

/*! Gets the value of the variable 'MOTORUP' that is defined in the default interface scope. */ 
extern const sc_integer tp1_04Iface_get_mOTORUP(const Tp1_04* handle);
/*! Gets the value of the variable 'MOTORDOWN' that is defined in the default interface scope. */ 
extern const sc_integer tp1_04Iface_get_mOTORDOWN(const Tp1_04* handle);
/*! Gets the value of the variable 'MOTOR_ON' that is defined in the default interface scope. */ 
extern const sc_boolean tp1_04Iface_get_mOTOR_ON(const Tp1_04* handle);
/*! Gets the value of the variable 'MOTOR_OFF' that is defined in the default interface scope. */ 
extern const sc_boolean tp1_04Iface_get_mOTOR_OFF(const Tp1_04* handle);
/*! Gets the value of the variable 'SENSP' that is defined in the default interface scope. */ 
extern const sc_integer tp1_04Iface_get_sENSP(const Tp1_04* handle);
/*! Gets the value of the variable 'FCARRI' that is defined in the default interface scope. */ 
extern const sc_integer tp1_04Iface_get_fCARRI(const Tp1_04* handle);
/*! Gets the value of the variable 'FCARRF' that is defined in the default interface scope. */ 
extern const sc_integer tp1_04Iface_get_fCARRF(const Tp1_04* handle);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean tp1_04_isActive(const Tp1_04* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean tp1_04_isFinal(const Tp1_04* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean tp1_04_isStateActive(const Tp1_04* handle, Tp1_04States state);


#ifdef __cplusplus
}
#endif 

#endif /* TP1_04_H_ */
