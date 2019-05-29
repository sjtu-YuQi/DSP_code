/*
 * parameters.h
 *
 *  Created on: May 9, 2019
 *      Author: YuQi
 */

#ifndef PARAMETERS_H_
#define PARAMETERS_H_

#define EPWM1_MIN_DB   6
#define EPWM2_MIN_DB   6
#define EPWM3_MIN_DB   6
#define EPWM4_MIN_DB   6

// To keep track of which way the Dead Band is moving
#define DB_UP   1
#define DB_DOWN 0


#define DUTY 40
#define TB_BASE 900

#define COMP_VAL1 1000
#define COMP_VAL2 500
#define COMP_VAL3 500
#define COMP_VAL4 1000
//#define COMP_VAL1 700
//#define COMP_VAL2 700
//#define COMP_VAL3 700
//#define COMP_VAL4 700

//#define COMP_VAL1 500
//#define COMP_VAL2 1000
//#define COMP_VAL3 500
//#define COMP_VAL4 1000

#define TOTEM
/*
 * 单极性调制
 */
#ifdef UNIPOLAR

#define TB_PHASE1 0
#define TB_PHASE2 TB_BASE
#define TB_PHASE3 TB_BASE/2
#define TB_PHASE4 TB_BASE/2

#define SYN_DIR1 1
#define SYN_DIR2 0
#define SYN_DIR3 0
#define SYN_DIR4 1
#endif

/*
 * 双极性调制
 */
#ifdef BIPOLAR
#define TB_PHASE1 0
#define TB_PHASE2 0
#define TB_PHASE3 TB_BASE
#define TB_PHASE4 TB_BASE

#define SYN_DIR1 1
#define SYN_DIR2 1
#define SYN_DIR3 0
#define SYN_DIR4 0
#endif

#ifdef  TOTEM
#define TB_PHASE1 0
#define TB_PHASE2 0
#define TB_PHASE3 TB_BASE
#define TB_PHASE4 TB_BASE

#define SYN_DIR1 1
#define SYN_DIR2 1
#define SYN_DIR3 0
#define SYN_DIR4 0
#endif

#ifdef  D_TOTEM

#define TB_PHASE1 0
#define TB_PHASE2 0
#define TB_PHASE3 TB_BASE
#define TB_PHASE4 TB_BASE

#define SYN_DIR1 1
#define SYN_DIR2 1
#define SYN_DIR3 0
#define SYN_DIR4 0
#endif

#endif /* PARAMETERS_H_ */
