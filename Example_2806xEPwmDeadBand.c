#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File
#include "parameters.h"
void InitEPwm1Example(void);
void InitEPwm2Example(void);
void InitEPwm3Example(void);
void InitEPwm4Example(void);

__interrupt void epwm1_isr(void);
__interrupt void epwm2_isr(void);
__interrupt void epwm3_isr(void);

extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadEnd;
extern Uint16 RamfuncsRunStart;



void main(void)
{

    InitSysCtrl();
   InitEPwm1Gpio();
   InitEPwm2Gpio();
   InitEPwm3Gpio();
   InitEPwm4Gpio();
   
   DINT;

   InitPieCtrl();
   
   IER = 0x0000;
   IFR = 0x0000;
   InitPieVectTable();

   memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (Uint32)&RamfuncsRunStart);
   InitFlash();

   EALLOW;
   GpioCtrlRegs.GPAPUD.bit.GPIO30 = 0;                             //选择开启GPIO30上拉
   GpioCtrlRegs.GPAMUX2.bit.GPIO30 = 0;                            //选择GPIO30为普通 GPIO功能
   GpioCtrlRegs.GPADIR.bit.GPIO30 = 1;                             //配置GPIO30为输出引脚
   GpioDataRegs.GPADAT.bit.GPIO30=0;                               //配置GPIO30输出低电平

   EDIS;

   EALLOW;  // This is needed to write to EALLOW protected registers
   PieVectTable.EPWM1_INT = &epwm1_isr;
   PieVectTable.EPWM2_INT = &epwm2_isr;
   PieVectTable.EPWM3_INT = &epwm3_isr;      
   EDIS;    // This is needed to disable write to EALLOW protected registers

   EALLOW;
   SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;
   EDIS;

   InitEPwm1Example();    
   InitEPwm2Example();
   InitEPwm3Example();
   InitEPwm4Example();

   EALLOW;
   SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;
   EDIS;
   
// Enable CPU INT3 which is connected to EPWM1-3 INT:
   IER |= M_INT3;

// Enable EPWM INTn in the PIE: Group 3 interrupt 1-3
   PieCtrlRegs.PIEIER3.bit.INTx1 = 1;
   PieCtrlRegs.PIEIER3.bit.INTx2 = 1;
   PieCtrlRegs.PIEIER3.bit.INTx3 = 1;

// Enable global Interrupts and higher priority real-time debug events:
   EINT;   // Enable Global interrupt INTM
   ERTM;   // Enable Global realtime interrupt DBGM

// Step 6. IDLE loop. Just sit and loop forever (optional):
   for(;;)
   {
      __asm("          NOP");
   }

}

__interrupt void epwm1_isr(void)
{
   // Clear INT flag for this timer
   EPwm1Regs.ETCLR.bit.INT = 1;
   
   // Acknowledge this interrupt to receive more interrupts from group 3
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

}

__interrupt void epwm2_isr(void)
{

   // Clear INT flag for this timer
   EPwm2Regs.ETCLR.bit.INT = 1;
   
   // Acknowledge this interrupt to receive more interrupts from group 3
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

}

__interrupt void epwm3_isr(void)
{

   // Clear INT flag for this timer
   EPwm3Regs.ETCLR.bit.INT = 1;
   // Acknowledge this interrupt to receive more interrupts from group 3
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

}

void InitEPwm1Example()
{

   EPwm1Regs.TBPRD = TB_BASE;                        // Set timer period
   EPwm1Regs.TBPHS.half.TBPHS = TB_PHASE1;           // Phase is 0
   EPwm1Regs.TBCTR = 0x0000;                      // Clear counter
   EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO;  // Pass through
   EPwm1Regs.TBCTL.bit.PHSDIR = SYN_DIR1;   //when syni comes, continue to count up

   // Setup TBCLK
   EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
   EPwm1Regs.TBCTL.bit.PHSEN = TB_ENABLE;        // Disable phase loading
   EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
   EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;

   EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;    // Load registers every ZERO
   EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
   EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
   EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;   

   // Setup compare 
   EPwm1Regs.CMPA.half.CMPA = COMP_VAL1;
   
   // Set actions
   EPwm1Regs.AQCTLA.bit.CAU = AQ_CLEAR;         // Set PWM1A on CAU
   EPwm1Regs.AQCTLA.bit.CAD = AQ_SET;			  // Clear PWM1A on CAD
//   EPwm1Regs.AQCTLB.bit.CAU = AQ_SET;           // Clear PWM1B on CAU
//   EPwm1Regs.AQCTLB.bit.CAD = AQ_CLEAR;             // Set PWM1B on CAD

   // Active Low PWMs - Setup Deadband
   EPwm1Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
   EPwm1Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
   EPwm1Regs.DBCTL.bit.IN_MODE = DBA_ALL;
   EPwm1Regs.DBRED = EPWM1_MIN_DB;
   EPwm1Regs.DBFED = EPWM1_MIN_DB;
   
   // Interrupt where we will change the Deadband
   EPwm1Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;     // Select INT on Zero event
   EPwm1Regs.ETSEL.bit.INTEN = 1;                // Enable INT
   EPwm1Regs.ETPS.bit.INTPRD = ET_3RD;           // Generate INT on 3rd event   

}

void InitEPwm2Example()
{
   EPwm2Regs.TBPRD = TB_BASE;                        // Set timer period
   EPwm2Regs.TBPHS.half.TBPHS = TB_PHASE2;           // Phase is 0
   EPwm2Regs.TBCTR = 0x0000;                      // Clear counter
   EPwm2Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;  // Pass through
   EPwm2Regs.TBCTL.bit.PHSDIR = SYN_DIR2;   //when syni comes, continue to count up
   // Setup TBCLK
   EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
   EPwm2Regs.TBCTL.bit.PHSEN = TB_ENABLE;        // Disable phase loading
   EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
   EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV1;          // Slow just to observe on the scope

   // Setup compare 
   EPwm2Regs.CMPA.half.CMPA = COMP_VAL2;

   // Set actions
   EPwm2Regs.AQCTLA.bit.CAU = AQ_SET;             // Set PWM2A on CAU
   EPwm2Regs.AQCTLA.bit.CAD = AQ_CLEAR;           // Clear PWM2A on CAD


//   EPwm2Regs.AQCTLB.bit.CAU = AQ_SET;           // Clear PWM2B on CAU
//   EPwm2Regs.AQCTLB.bit.CAD = AQ_CLEAR;             // Set PWM2B on CAD

   // Active Low complementary PWMs - setup the deadband
   EPwm2Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
   EPwm2Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
   EPwm2Regs.DBCTL.bit.IN_MODE = DBA_ALL;
   EPwm2Regs.DBRED = EPWM2_MIN_DB;
   EPwm2Regs.DBFED = EPWM2_MIN_DB;

   // Interrupt where we will modify the deadband
   EPwm2Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;      // Select INT on Zero event
   EPwm2Regs.ETSEL.bit.INTEN = 1;                 // Enable INT
   EPwm2Regs.ETPS.bit.INTPRD = ET_3RD;            // Generate INT on 3rd event   
}

void InitEPwm3Example()
{
   EPwm3Regs.TBPRD = TB_BASE;                         // Set timer period
   EPwm3Regs.TBPHS.half.TBPHS = TB_PHASE3;            // Phase is 0
   EPwm3Regs.TBCTR = 0x0000;                       // Clear counter
   EPwm3Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;  // Pass through
   EPwm3Regs.TBCTL.bit.PHSDIR = SYN_DIR3;   //when syni comes, continue to count up
   // Setup TBCLK
   EPwm3Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
   EPwm3Regs.TBCTL.bit.PHSEN = TB_ENABLE;        // Disable phase loading
   EPwm3Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
   EPwm3Regs.TBCTL.bit.CLKDIV = TB_DIV1;          // Slow so we can observe on the scope

   // Setup compare 
   EPwm3Regs.CMPA.half.CMPA = COMP_VAL3;

   // Set actions
   EPwm3Regs.AQCTLA.bit.CAU = AQ_CLEAR;              // Set PWM3A on CAU
   EPwm3Regs.AQCTLA.bit.CAD = AQ_SET;            // Clear PWM3A on CAD
   
//   EPwm3Regs.AQCTLB.bit.CAU = AQ_SET;            // Clear PWM3B on CAU
//   EPwm3Regs.AQCTLB.bit.CAD = AQ_CLEAR;              // Set PWM3B on CAD

   EPwm3Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
   EPwm3Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
   EPwm3Regs.DBCTL.bit.IN_MODE = DBA_ALL;
   EPwm3Regs.DBRED = EPWM3_MIN_DB;
   EPwm3Regs.DBFED = EPWM3_MIN_DB;
   
   EPwm3Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;       // Select INT on Zero event
   EPwm3Regs.ETSEL.bit.INTEN = 1;                  // Enable INT
   EPwm3Regs.ETPS.bit.INTPRD = ET_3RD;             // Generate INT on 3rd event   
   
}
void InitEPwm4Example()
{
   EPwm4Regs.TBPRD = TB_BASE;                         // Set timer period
   EPwm4Regs.TBPHS.half.TBPHS = TB_PHASE4;            // Phase is 0
   EPwm4Regs.TBCTR = 0x0000;                       // Clear counter
   EPwm4Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;  // Pass through
   EPwm4Regs.TBCTL.bit.PHSDIR = SYN_DIR4;   //when syni comes, continue to count up
   // Setup TBCLK
   EPwm4Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up
   EPwm4Regs.TBCTL.bit.PHSEN = TB_ENABLE;        // Disable phase loading
   EPwm4Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
   EPwm4Regs.TBCTL.bit.CLKDIV = TB_DIV1;          // Slow so we can observe on the scope

   // Setup compare
   EPwm4Regs.CMPA.half.CMPA = COMP_VAL4;

   // Set actions
   EPwm4Regs.AQCTLA.bit.CAU = AQ_SET;              // Set PWM3A on CAU
   EPwm4Regs.AQCTLA.bit.CAD = AQ_CLEAR;            // Clear PWM3A on CAD

//   EPwm4Regs.AQCTLB.bit.CAU = AQ_SET;            // Clear PWM3B on CAU
//   EPwm4Regs.AQCTLB.bit.CAD = AQ_CLEAR;              // Set PWM3B on CAD

   EPwm4Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
   EPwm4Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
   EPwm4Regs.DBCTL.bit.IN_MODE = DBA_ALL;
   EPwm4Regs.DBRED = EPWM4_MIN_DB;
   EPwm4Regs.DBFED = EPWM4_MIN_DB;

}
