.ifndef INCLUDED_CYFITTERGNU_INC
.set INCLUDED_CYFITTERGNU_INC, 1
.include "cydevicegnu.inc"
.include "cydevicegnu_trm.inc"

/* A0 */
.set A0__0__MASK, 0x10
.set A0__0__PC, CYREG_IO_PC_PRT15_PC4
.set A0__0__PORT, 15
.set A0__0__SHIFT, 4
.set A0__AG, CYREG_PRT15_AG
.set A0__AMUX, CYREG_PRT15_AMUX
.set A0__BIE, CYREG_PRT15_BIE
.set A0__BIT_MASK, CYREG_PRT15_BIT_MASK
.set A0__BYP, CYREG_PRT15_BYP
.set A0__CTL, CYREG_PRT15_CTL
.set A0__DM0, CYREG_PRT15_DM0
.set A0__DM1, CYREG_PRT15_DM1
.set A0__DM2, CYREG_PRT15_DM2
.set A0__DR, CYREG_PRT15_DR
.set A0__INP_DIS, CYREG_PRT15_INP_DIS
.set A0__LCD_COM_SEG, CYREG_PRT15_LCD_COM_SEG
.set A0__LCD_EN, CYREG_PRT15_LCD_EN
.set A0__MASK, 0x10
.set A0__PORT, 15
.set A0__PRT, CYREG_PRT15_PRT
.set A0__PRTDSI__CAPS_SEL, CYREG_PRT15_CAPS_SEL
.set A0__PRTDSI__DBL_SYNC_IN, CYREG_PRT15_DBL_SYNC_IN
.set A0__PRTDSI__OE_SEL0, CYREG_PRT15_OE_SEL0
.set A0__PRTDSI__OE_SEL1, CYREG_PRT15_OE_SEL1
.set A0__PRTDSI__OUT_SEL0, CYREG_PRT15_OUT_SEL0
.set A0__PRTDSI__OUT_SEL1, CYREG_PRT15_OUT_SEL1
.set A0__PRTDSI__SYNC_OUT, CYREG_PRT15_SYNC_OUT
.set A0__PS, CYREG_PRT15_PS
.set A0__SHIFT, 4
.set A0__SLW, CYREG_PRT15_SLW

/* A1 */
.set A1__0__MASK, 0x20
.set A1__0__PC, CYREG_IO_PC_PRT15_PC5
.set A1__0__PORT, 15
.set A1__0__SHIFT, 5
.set A1__AG, CYREG_PRT15_AG
.set A1__AMUX, CYREG_PRT15_AMUX
.set A1__BIE, CYREG_PRT15_BIE
.set A1__BIT_MASK, CYREG_PRT15_BIT_MASK
.set A1__BYP, CYREG_PRT15_BYP
.set A1__CTL, CYREG_PRT15_CTL
.set A1__DM0, CYREG_PRT15_DM0
.set A1__DM1, CYREG_PRT15_DM1
.set A1__DM2, CYREG_PRT15_DM2
.set A1__DR, CYREG_PRT15_DR
.set A1__INP_DIS, CYREG_PRT15_INP_DIS
.set A1__LCD_COM_SEG, CYREG_PRT15_LCD_COM_SEG
.set A1__LCD_EN, CYREG_PRT15_LCD_EN
.set A1__MASK, 0x20
.set A1__PORT, 15
.set A1__PRT, CYREG_PRT15_PRT
.set A1__PRTDSI__CAPS_SEL, CYREG_PRT15_CAPS_SEL
.set A1__PRTDSI__DBL_SYNC_IN, CYREG_PRT15_DBL_SYNC_IN
.set A1__PRTDSI__OE_SEL0, CYREG_PRT15_OE_SEL0
.set A1__PRTDSI__OE_SEL1, CYREG_PRT15_OE_SEL1
.set A1__PRTDSI__OUT_SEL0, CYREG_PRT15_OUT_SEL0
.set A1__PRTDSI__OUT_SEL1, CYREG_PRT15_OUT_SEL1
.set A1__PRTDSI__SYNC_OUT, CYREG_PRT15_SYNC_OUT
.set A1__PS, CYREG_PRT15_PS
.set A1__SHIFT, 5
.set A1__SLW, CYREG_PRT15_SLW

/* ADC_ADC_SAR */
.set ADC_ADC_SAR__CLK, CYREG_SAR1_CLK
.set ADC_ADC_SAR__CSR0, CYREG_SAR1_CSR0
.set ADC_ADC_SAR__CSR1, CYREG_SAR1_CSR1
.set ADC_ADC_SAR__CSR2, CYREG_SAR1_CSR2
.set ADC_ADC_SAR__CSR3, CYREG_SAR1_CSR3
.set ADC_ADC_SAR__CSR4, CYREG_SAR1_CSR4
.set ADC_ADC_SAR__CSR5, CYREG_SAR1_CSR5
.set ADC_ADC_SAR__CSR6, CYREG_SAR1_CSR6
.set ADC_ADC_SAR__PM_ACT_CFG, CYREG_PM_ACT_CFG11
.set ADC_ADC_SAR__PM_ACT_MSK, 0x02
.set ADC_ADC_SAR__PM_STBY_CFG, CYREG_PM_STBY_CFG11
.set ADC_ADC_SAR__PM_STBY_MSK, 0x02
.set ADC_ADC_SAR__SW0, CYREG_SAR1_SW0
.set ADC_ADC_SAR__SW2, CYREG_SAR1_SW2
.set ADC_ADC_SAR__SW3, CYREG_SAR1_SW3
.set ADC_ADC_SAR__SW4, CYREG_SAR1_SW4
.set ADC_ADC_SAR__SW6, CYREG_SAR1_SW6
.set ADC_ADC_SAR__TR0, CYREG_SAR1_TR0
.set ADC_ADC_SAR__WRK0, CYREG_SAR1_WRK0
.set ADC_ADC_SAR__WRK1, CYREG_SAR1_WRK1

/* ADC_Bypass */
.set ADC_Bypass__0__MASK, 0x04
.set ADC_Bypass__0__PC, CYREG_PRT0_PC2
.set ADC_Bypass__0__PORT, 0
.set ADC_Bypass__0__SHIFT, 2
.set ADC_Bypass__AG, CYREG_PRT0_AG
.set ADC_Bypass__AMUX, CYREG_PRT0_AMUX
.set ADC_Bypass__BIE, CYREG_PRT0_BIE
.set ADC_Bypass__BIT_MASK, CYREG_PRT0_BIT_MASK
.set ADC_Bypass__BYP, CYREG_PRT0_BYP
.set ADC_Bypass__CTL, CYREG_PRT0_CTL
.set ADC_Bypass__DM0, CYREG_PRT0_DM0
.set ADC_Bypass__DM1, CYREG_PRT0_DM1
.set ADC_Bypass__DM2, CYREG_PRT0_DM2
.set ADC_Bypass__DR, CYREG_PRT0_DR
.set ADC_Bypass__INP_DIS, CYREG_PRT0_INP_DIS
.set ADC_Bypass__LCD_COM_SEG, CYREG_PRT0_LCD_COM_SEG
.set ADC_Bypass__LCD_EN, CYREG_PRT0_LCD_EN
.set ADC_Bypass__MASK, 0x04
.set ADC_Bypass__PORT, 0
.set ADC_Bypass__PRT, CYREG_PRT0_PRT
.set ADC_Bypass__PRTDSI__CAPS_SEL, CYREG_PRT0_CAPS_SEL
.set ADC_Bypass__PRTDSI__DBL_SYNC_IN, CYREG_PRT0_DBL_SYNC_IN
.set ADC_Bypass__PRTDSI__OE_SEL0, CYREG_PRT0_OE_SEL0
.set ADC_Bypass__PRTDSI__OE_SEL1, CYREG_PRT0_OE_SEL1
.set ADC_Bypass__PRTDSI__OUT_SEL0, CYREG_PRT0_OUT_SEL0
.set ADC_Bypass__PRTDSI__OUT_SEL1, CYREG_PRT0_OUT_SEL1
.set ADC_Bypass__PRTDSI__SYNC_OUT, CYREG_PRT0_SYNC_OUT
.set ADC_Bypass__PS, CYREG_PRT0_PS
.set ADC_Bypass__SHIFT, 2
.set ADC_Bypass__SLW, CYREG_PRT0_SLW

/* ADC_IRQ */
.set ADC_IRQ__INTC_CLR_EN_REG, CYREG_NVIC_CLRENA0
.set ADC_IRQ__INTC_CLR_PD_REG, CYREG_NVIC_CLRPEND0
.set ADC_IRQ__INTC_MASK, 0x01
.set ADC_IRQ__INTC_NUMBER, 0
.set ADC_IRQ__INTC_PRIOR_NUM, 7
.set ADC_IRQ__INTC_PRIOR_REG, CYREG_NVIC_PRI_0
.set ADC_IRQ__INTC_SET_EN_REG, CYREG_NVIC_SETENA0
.set ADC_IRQ__INTC_SET_PD_REG, CYREG_NVIC_SETPEND0

/* ADC_theACLK */
.set ADC_theACLK__CFG0, CYREG_CLKDIST_DCFG1_CFG0
.set ADC_theACLK__CFG1, CYREG_CLKDIST_DCFG1_CFG1
.set ADC_theACLK__CFG2, CYREG_CLKDIST_DCFG1_CFG2
.set ADC_theACLK__CFG2_SRC_SEL_MASK, 0x07
.set ADC_theACLK__INDEX, 0x01
.set ADC_theACLK__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set ADC_theACLK__PM_ACT_MSK, 0x02
.set ADC_theACLK__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set ADC_theACLK__PM_STBY_MSK, 0x02

/* A_B_DacClk */
.set A_B_DacClk__CFG0, CYREG_CLKDIST_DCFG3_CFG0
.set A_B_DacClk__CFG1, CYREG_CLKDIST_DCFG3_CFG1
.set A_B_DacClk__CFG2, CYREG_CLKDIST_DCFG3_CFG2
.set A_B_DacClk__CFG2_SRC_SEL_MASK, 0x07
.set A_B_DacClk__INDEX, 0x03
.set A_B_DacClk__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set A_B_DacClk__PM_ACT_MSK, 0x08
.set A_B_DacClk__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set A_B_DacClk__PM_STBY_MSK, 0x08

/* A_B_VDAC8_viDAC8 */
.set A_B_VDAC8_viDAC8__CR0, CYREG_DAC3_CR0
.set A_B_VDAC8_viDAC8__CR1, CYREG_DAC3_CR1
.set A_B_VDAC8_viDAC8__D, CYREG_DAC3_D
.set A_B_VDAC8_viDAC8__PM_ACT_CFG, CYREG_PM_ACT_CFG8
.set A_B_VDAC8_viDAC8__PM_ACT_MSK, 0x08
.set A_B_VDAC8_viDAC8__PM_STBY_CFG, CYREG_PM_STBY_CFG8
.set A_B_VDAC8_viDAC8__PM_STBY_MSK, 0x08
.set A_B_VDAC8_viDAC8__STROBE, CYREG_DAC3_STROBE
.set A_B_VDAC8_viDAC8__SW0, CYREG_DAC3_SW0
.set A_B_VDAC8_viDAC8__SW2, CYREG_DAC3_SW2
.set A_B_VDAC8_viDAC8__SW3, CYREG_DAC3_SW3
.set A_B_VDAC8_viDAC8__SW4, CYREG_DAC3_SW4
.set A_B_VDAC8_viDAC8__TR, CYREG_DAC3_TR
.set A_B_VDAC8_viDAC8__TRIM__M1, CYREG_FLSHID_CUST_TABLES_DAC3_M1
.set A_B_VDAC8_viDAC8__TRIM__M2, CYREG_FLSHID_CUST_TABLES_DAC3_M2
.set A_B_VDAC8_viDAC8__TRIM__M3, CYREG_FLSHID_CUST_TABLES_DAC3_M3
.set A_B_VDAC8_viDAC8__TRIM__M4, CYREG_FLSHID_CUST_TABLES_DAC3_M4
.set A_B_VDAC8_viDAC8__TRIM__M5, CYREG_FLSHID_CUST_TABLES_DAC3_M5
.set A_B_VDAC8_viDAC8__TRIM__M6, CYREG_FLSHID_CUST_TABLES_DAC3_M6
.set A_B_VDAC8_viDAC8__TRIM__M7, CYREG_FLSHID_CUST_TABLES_DAC3_M7
.set A_B_VDAC8_viDAC8__TRIM__M8, CYREG_FLSHID_CUST_TABLES_DAC3_M8
.set A_B_VDAC8_viDAC8__TST, CYREG_DAC3_TST

/* A_B_Wave1_DMA */
.set A_B_Wave1_DMA__DRQ_CTL, CYREG_IDMUX_DRQ_CTL0
.set A_B_Wave1_DMA__DRQ_NUMBER, 0
.set A_B_Wave1_DMA__NUMBEROF_TDS, 0
.set A_B_Wave1_DMA__PRIORITY, 2
.set A_B_Wave1_DMA__TERMIN_EN, 0
.set A_B_Wave1_DMA__TERMIN_SEL, 0
.set A_B_Wave1_DMA__TERMOUT0_EN, 0
.set A_B_Wave1_DMA__TERMOUT0_SEL, 0
.set A_B_Wave1_DMA__TERMOUT1_EN, 0
.set A_B_Wave1_DMA__TERMOUT1_SEL, 0

/* A_B_Wave2_DMA */
.set A_B_Wave2_DMA__DRQ_CTL, CYREG_IDMUX_DRQ_CTL0
.set A_B_Wave2_DMA__DRQ_NUMBER, 1
.set A_B_Wave2_DMA__NUMBEROF_TDS, 0
.set A_B_Wave2_DMA__PRIORITY, 2
.set A_B_Wave2_DMA__TERMIN_EN, 0
.set A_B_Wave2_DMA__TERMIN_SEL, 0
.set A_B_Wave2_DMA__TERMOUT0_EN, 0
.set A_B_Wave2_DMA__TERMOUT0_SEL, 0
.set A_B_Wave2_DMA__TERMOUT1_EN, 0
.set A_B_Wave2_DMA__TERMOUT1_SEL, 0

/* Amp_SC */
.set Amp_SC__BST, CYREG_SC0_BST
.set Amp_SC__CLK, CYREG_SC0_CLK
.set Amp_SC__CMPINV, CYREG_SC_CMPINV
.set Amp_SC__CMPINV_MASK, 0x01
.set Amp_SC__CPTR, CYREG_SC_CPTR
.set Amp_SC__CPTR_MASK, 0x01
.set Amp_SC__CR0, CYREG_SC0_CR0
.set Amp_SC__CR1, CYREG_SC0_CR1
.set Amp_SC__CR2, CYREG_SC0_CR2
.set Amp_SC__MSK, CYREG_SC_MSK
.set Amp_SC__MSK_MASK, 0x01
.set Amp_SC__PM_ACT_CFG, CYREG_PM_ACT_CFG9
.set Amp_SC__PM_ACT_MSK, 0x01
.set Amp_SC__PM_STBY_CFG, CYREG_PM_STBY_CFG9
.set Amp_SC__PM_STBY_MSK, 0x01
.set Amp_SC__SR, CYREG_SC_SR
.set Amp_SC__SR_MASK, 0x01
.set Amp_SC__SW0, CYREG_SC0_SW0
.set Amp_SC__SW10, CYREG_SC0_SW10
.set Amp_SC__SW2, CYREG_SC0_SW2
.set Amp_SC__SW3, CYREG_SC0_SW3
.set Amp_SC__SW4, CYREG_SC0_SW4
.set Amp_SC__SW6, CYREG_SC0_SW6
.set Amp_SC__SW7, CYREG_SC0_SW7
.set Amp_SC__SW8, CYREG_SC0_SW8
.set Amp_SC__WRK1, CYREG_SC_WRK1
.set Amp_SC__WRK1_MASK, 0x01

/* C_D_DacClk */
.set C_D_DacClk__CFG0, CYREG_CLKDIST_DCFG4_CFG0
.set C_D_DacClk__CFG1, CYREG_CLKDIST_DCFG4_CFG1
.set C_D_DacClk__CFG2, CYREG_CLKDIST_DCFG4_CFG2
.set C_D_DacClk__CFG2_SRC_SEL_MASK, 0x07
.set C_D_DacClk__INDEX, 0x04
.set C_D_DacClk__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set C_D_DacClk__PM_ACT_MSK, 0x10
.set C_D_DacClk__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set C_D_DacClk__PM_STBY_MSK, 0x10

/* C_D_VDAC8_viDAC8 */
.set C_D_VDAC8_viDAC8__CR0, CYREG_DAC1_CR0
.set C_D_VDAC8_viDAC8__CR1, CYREG_DAC1_CR1
.set C_D_VDAC8_viDAC8__D, CYREG_DAC1_D
.set C_D_VDAC8_viDAC8__PM_ACT_CFG, CYREG_PM_ACT_CFG8
.set C_D_VDAC8_viDAC8__PM_ACT_MSK, 0x02
.set C_D_VDAC8_viDAC8__PM_STBY_CFG, CYREG_PM_STBY_CFG8
.set C_D_VDAC8_viDAC8__PM_STBY_MSK, 0x02
.set C_D_VDAC8_viDAC8__STROBE, CYREG_DAC1_STROBE
.set C_D_VDAC8_viDAC8__SW0, CYREG_DAC1_SW0
.set C_D_VDAC8_viDAC8__SW2, CYREG_DAC1_SW2
.set C_D_VDAC8_viDAC8__SW3, CYREG_DAC1_SW3
.set C_D_VDAC8_viDAC8__SW4, CYREG_DAC1_SW4
.set C_D_VDAC8_viDAC8__TR, CYREG_DAC1_TR
.set C_D_VDAC8_viDAC8__TRIM__M1, CYREG_FLSHID_CUST_TABLES_DAC1_M1
.set C_D_VDAC8_viDAC8__TRIM__M2, CYREG_FLSHID_CUST_TABLES_DAC1_M2
.set C_D_VDAC8_viDAC8__TRIM__M3, CYREG_FLSHID_CUST_TABLES_DAC1_M3
.set C_D_VDAC8_viDAC8__TRIM__M4, CYREG_FLSHID_CUST_TABLES_DAC1_M4
.set C_D_VDAC8_viDAC8__TRIM__M5, CYREG_FLSHID_CUST_TABLES_DAC1_M5
.set C_D_VDAC8_viDAC8__TRIM__M6, CYREG_FLSHID_CUST_TABLES_DAC1_M6
.set C_D_VDAC8_viDAC8__TRIM__M7, CYREG_FLSHID_CUST_TABLES_DAC1_M7
.set C_D_VDAC8_viDAC8__TRIM__M8, CYREG_FLSHID_CUST_TABLES_DAC1_M8
.set C_D_VDAC8_viDAC8__TST, CYREG_DAC1_TST

/* C_D_Wave1_DMA */
.set C_D_Wave1_DMA__DRQ_CTL, CYREG_IDMUX_DRQ_CTL0
.set C_D_Wave1_DMA__DRQ_NUMBER, 2
.set C_D_Wave1_DMA__NUMBEROF_TDS, 0
.set C_D_Wave1_DMA__PRIORITY, 2
.set C_D_Wave1_DMA__TERMIN_EN, 0
.set C_D_Wave1_DMA__TERMIN_SEL, 0
.set C_D_Wave1_DMA__TERMOUT0_EN, 0
.set C_D_Wave1_DMA__TERMOUT0_SEL, 0
.set C_D_Wave1_DMA__TERMOUT1_EN, 0
.set C_D_Wave1_DMA__TERMOUT1_SEL, 0

/* C_D_Wave2_DMA */
.set C_D_Wave2_DMA__DRQ_CTL, CYREG_IDMUX_DRQ_CTL0
.set C_D_Wave2_DMA__DRQ_NUMBER, 3
.set C_D_Wave2_DMA__NUMBEROF_TDS, 0
.set C_D_Wave2_DMA__PRIORITY, 2
.set C_D_Wave2_DMA__TERMIN_EN, 0
.set C_D_Wave2_DMA__TERMIN_SEL, 0
.set C_D_Wave2_DMA__TERMOUT0_EN, 0
.set C_D_Wave2_DMA__TERMOUT0_SEL, 0
.set C_D_Wave2_DMA__TERMOUT1_EN, 0
.set C_D_Wave2_DMA__TERMOUT1_SEL, 0

/* E_F_DacClk */
.set E_F_DacClk__CFG0, CYREG_CLKDIST_DCFG2_CFG0
.set E_F_DacClk__CFG1, CYREG_CLKDIST_DCFG2_CFG1
.set E_F_DacClk__CFG2, CYREG_CLKDIST_DCFG2_CFG2
.set E_F_DacClk__CFG2_SRC_SEL_MASK, 0x07
.set E_F_DacClk__INDEX, 0x02
.set E_F_DacClk__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set E_F_DacClk__PM_ACT_MSK, 0x04
.set E_F_DacClk__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set E_F_DacClk__PM_STBY_MSK, 0x04

/* E_F_VDAC8_viDAC8 */
.set E_F_VDAC8_viDAC8__CR0, CYREG_DAC0_CR0
.set E_F_VDAC8_viDAC8__CR1, CYREG_DAC0_CR1
.set E_F_VDAC8_viDAC8__D, CYREG_DAC0_D
.set E_F_VDAC8_viDAC8__PM_ACT_CFG, CYREG_PM_ACT_CFG8
.set E_F_VDAC8_viDAC8__PM_ACT_MSK, 0x01
.set E_F_VDAC8_viDAC8__PM_STBY_CFG, CYREG_PM_STBY_CFG8
.set E_F_VDAC8_viDAC8__PM_STBY_MSK, 0x01
.set E_F_VDAC8_viDAC8__STROBE, CYREG_DAC0_STROBE
.set E_F_VDAC8_viDAC8__SW0, CYREG_DAC0_SW0
.set E_F_VDAC8_viDAC8__SW2, CYREG_DAC0_SW2
.set E_F_VDAC8_viDAC8__SW3, CYREG_DAC0_SW3
.set E_F_VDAC8_viDAC8__SW4, CYREG_DAC0_SW4
.set E_F_VDAC8_viDAC8__TR, CYREG_DAC0_TR
.set E_F_VDAC8_viDAC8__TRIM__M1, CYREG_FLSHID_CUST_TABLES_DAC0_M1
.set E_F_VDAC8_viDAC8__TRIM__M2, CYREG_FLSHID_CUST_TABLES_DAC0_M2
.set E_F_VDAC8_viDAC8__TRIM__M3, CYREG_FLSHID_CUST_TABLES_DAC0_M3
.set E_F_VDAC8_viDAC8__TRIM__M4, CYREG_FLSHID_CUST_TABLES_DAC0_M4
.set E_F_VDAC8_viDAC8__TRIM__M5, CYREG_FLSHID_CUST_TABLES_DAC0_M5
.set E_F_VDAC8_viDAC8__TRIM__M6, CYREG_FLSHID_CUST_TABLES_DAC0_M6
.set E_F_VDAC8_viDAC8__TRIM__M7, CYREG_FLSHID_CUST_TABLES_DAC0_M7
.set E_F_VDAC8_viDAC8__TRIM__M8, CYREG_FLSHID_CUST_TABLES_DAC0_M8
.set E_F_VDAC8_viDAC8__TST, CYREG_DAC0_TST

/* E_F_Wave1_DMA */
.set E_F_Wave1_DMA__DRQ_CTL, CYREG_IDMUX_DRQ_CTL1
.set E_F_Wave1_DMA__DRQ_NUMBER, 4
.set E_F_Wave1_DMA__NUMBEROF_TDS, 0
.set E_F_Wave1_DMA__PRIORITY, 2
.set E_F_Wave1_DMA__TERMIN_EN, 0
.set E_F_Wave1_DMA__TERMIN_SEL, 0
.set E_F_Wave1_DMA__TERMOUT0_EN, 0
.set E_F_Wave1_DMA__TERMOUT0_SEL, 0
.set E_F_Wave1_DMA__TERMOUT1_EN, 0
.set E_F_Wave1_DMA__TERMOUT1_SEL, 0

/* E_F_Wave2_DMA */
.set E_F_Wave2_DMA__DRQ_CTL, CYREG_IDMUX_DRQ_CTL1
.set E_F_Wave2_DMA__DRQ_NUMBER, 5
.set E_F_Wave2_DMA__NUMBEROF_TDS, 0
.set E_F_Wave2_DMA__PRIORITY, 2
.set E_F_Wave2_DMA__TERMIN_EN, 0
.set E_F_Wave2_DMA__TERMIN_SEL, 0
.set E_F_Wave2_DMA__TERMOUT0_EN, 0
.set E_F_Wave2_DMA__TERMOUT0_SEL, 0
.set E_F_Wave2_DMA__TERMOUT1_EN, 0
.set E_F_Wave2_DMA__TERMOUT1_SEL, 0

/* G_A_DacClk */
.set G_A_DacClk__CFG0, CYREG_CLKDIST_DCFG5_CFG0
.set G_A_DacClk__CFG1, CYREG_CLKDIST_DCFG5_CFG1
.set G_A_DacClk__CFG2, CYREG_CLKDIST_DCFG5_CFG2
.set G_A_DacClk__CFG2_SRC_SEL_MASK, 0x07
.set G_A_DacClk__INDEX, 0x05
.set G_A_DacClk__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set G_A_DacClk__PM_ACT_MSK, 0x20
.set G_A_DacClk__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set G_A_DacClk__PM_STBY_MSK, 0x20

/* G_A_VDAC8_viDAC8 */
.set G_A_VDAC8_viDAC8__CR0, CYREG_DAC2_CR0
.set G_A_VDAC8_viDAC8__CR1, CYREG_DAC2_CR1
.set G_A_VDAC8_viDAC8__D, CYREG_DAC2_D
.set G_A_VDAC8_viDAC8__PM_ACT_CFG, CYREG_PM_ACT_CFG8
.set G_A_VDAC8_viDAC8__PM_ACT_MSK, 0x04
.set G_A_VDAC8_viDAC8__PM_STBY_CFG, CYREG_PM_STBY_CFG8
.set G_A_VDAC8_viDAC8__PM_STBY_MSK, 0x04
.set G_A_VDAC8_viDAC8__STROBE, CYREG_DAC2_STROBE
.set G_A_VDAC8_viDAC8__SW0, CYREG_DAC2_SW0
.set G_A_VDAC8_viDAC8__SW2, CYREG_DAC2_SW2
.set G_A_VDAC8_viDAC8__SW3, CYREG_DAC2_SW3
.set G_A_VDAC8_viDAC8__SW4, CYREG_DAC2_SW4
.set G_A_VDAC8_viDAC8__TR, CYREG_DAC2_TR
.set G_A_VDAC8_viDAC8__TRIM__M1, CYREG_FLSHID_CUST_TABLES_DAC2_M1
.set G_A_VDAC8_viDAC8__TRIM__M2, CYREG_FLSHID_CUST_TABLES_DAC2_M2
.set G_A_VDAC8_viDAC8__TRIM__M3, CYREG_FLSHID_CUST_TABLES_DAC2_M3
.set G_A_VDAC8_viDAC8__TRIM__M4, CYREG_FLSHID_CUST_TABLES_DAC2_M4
.set G_A_VDAC8_viDAC8__TRIM__M5, CYREG_FLSHID_CUST_TABLES_DAC2_M5
.set G_A_VDAC8_viDAC8__TRIM__M6, CYREG_FLSHID_CUST_TABLES_DAC2_M6
.set G_A_VDAC8_viDAC8__TRIM__M7, CYREG_FLSHID_CUST_TABLES_DAC2_M7
.set G_A_VDAC8_viDAC8__TRIM__M8, CYREG_FLSHID_CUST_TABLES_DAC2_M8
.set G_A_VDAC8_viDAC8__TST, CYREG_DAC2_TST

/* G_A_Wave1_DMA */
.set G_A_Wave1_DMA__DRQ_CTL, CYREG_IDMUX_DRQ_CTL1
.set G_A_Wave1_DMA__DRQ_NUMBER, 6
.set G_A_Wave1_DMA__NUMBEROF_TDS, 0
.set G_A_Wave1_DMA__PRIORITY, 2
.set G_A_Wave1_DMA__TERMIN_EN, 0
.set G_A_Wave1_DMA__TERMIN_SEL, 0
.set G_A_Wave1_DMA__TERMOUT0_EN, 0
.set G_A_Wave1_DMA__TERMOUT0_SEL, 0
.set G_A_Wave1_DMA__TERMOUT1_EN, 0
.set G_A_Wave1_DMA__TERMOUT1_SEL, 0

/* G_A_Wave2_DMA */
.set G_A_Wave2_DMA__DRQ_CTL, CYREG_IDMUX_DRQ_CTL1
.set G_A_Wave2_DMA__DRQ_NUMBER, 7
.set G_A_Wave2_DMA__NUMBEROF_TDS, 0
.set G_A_Wave2_DMA__PRIORITY, 2
.set G_A_Wave2_DMA__TERMIN_EN, 0
.set G_A_Wave2_DMA__TERMIN_SEL, 0
.set G_A_Wave2_DMA__TERMOUT0_EN, 0
.set G_A_Wave2_DMA__TERMOUT0_SEL, 0
.set G_A_Wave2_DMA__TERMOUT1_EN, 0
.set G_A_Wave2_DMA__TERMOUT1_SEL, 0

/* A_Key */
.set A_Key__0__MASK, 0x01
.set A_Key__0__PC, CYREG_PRT5_PC0
.set A_Key__0__PORT, 5
.set A_Key__0__SHIFT, 0
.set A_Key__AG, CYREG_PRT5_AG
.set A_Key__AMUX, CYREG_PRT5_AMUX
.set A_Key__BIE, CYREG_PRT5_BIE
.set A_Key__BIT_MASK, CYREG_PRT5_BIT_MASK
.set A_Key__BYP, CYREG_PRT5_BYP
.set A_Key__CTL, CYREG_PRT5_CTL
.set A_Key__DM0, CYREG_PRT5_DM0
.set A_Key__DM1, CYREG_PRT5_DM1
.set A_Key__DM2, CYREG_PRT5_DM2
.set A_Key__DR, CYREG_PRT5_DR
.set A_Key__INP_DIS, CYREG_PRT5_INP_DIS
.set A_Key__LCD_COM_SEG, CYREG_PRT5_LCD_COM_SEG
.set A_Key__LCD_EN, CYREG_PRT5_LCD_EN
.set A_Key__MASK, 0x01
.set A_Key__PORT, 5
.set A_Key__PRT, CYREG_PRT5_PRT
.set A_Key__PRTDSI__CAPS_SEL, CYREG_PRT5_CAPS_SEL
.set A_Key__PRTDSI__DBL_SYNC_IN, CYREG_PRT5_DBL_SYNC_IN
.set A_Key__PRTDSI__OE_SEL0, CYREG_PRT5_OE_SEL0
.set A_Key__PRTDSI__OE_SEL1, CYREG_PRT5_OE_SEL1
.set A_Key__PRTDSI__OUT_SEL0, CYREG_PRT5_OUT_SEL0
.set A_Key__PRTDSI__OUT_SEL1, CYREG_PRT5_OUT_SEL1
.set A_Key__PRTDSI__SYNC_OUT, CYREG_PRT5_SYNC_OUT
.set A_Key__PS, CYREG_PRT5_PS
.set A_Key__SHIFT, 0
.set A_Key__SLW, CYREG_PRT5_SLW

/* B_Key */
.set B_Key__0__MASK, 0x02
.set B_Key__0__PC, CYREG_PRT5_PC1
.set B_Key__0__PORT, 5
.set B_Key__0__SHIFT, 1
.set B_Key__AG, CYREG_PRT5_AG
.set B_Key__AMUX, CYREG_PRT5_AMUX
.set B_Key__BIE, CYREG_PRT5_BIE
.set B_Key__BIT_MASK, CYREG_PRT5_BIT_MASK
.set B_Key__BYP, CYREG_PRT5_BYP
.set B_Key__CTL, CYREG_PRT5_CTL
.set B_Key__DM0, CYREG_PRT5_DM0
.set B_Key__DM1, CYREG_PRT5_DM1
.set B_Key__DM2, CYREG_PRT5_DM2
.set B_Key__DR, CYREG_PRT5_DR
.set B_Key__INP_DIS, CYREG_PRT5_INP_DIS
.set B_Key__LCD_COM_SEG, CYREG_PRT5_LCD_COM_SEG
.set B_Key__LCD_EN, CYREG_PRT5_LCD_EN
.set B_Key__MASK, 0x02
.set B_Key__PORT, 5
.set B_Key__PRT, CYREG_PRT5_PRT
.set B_Key__PRTDSI__CAPS_SEL, CYREG_PRT5_CAPS_SEL
.set B_Key__PRTDSI__DBL_SYNC_IN, CYREG_PRT5_DBL_SYNC_IN
.set B_Key__PRTDSI__OE_SEL0, CYREG_PRT5_OE_SEL0
.set B_Key__PRTDSI__OE_SEL1, CYREG_PRT5_OE_SEL1
.set B_Key__PRTDSI__OUT_SEL0, CYREG_PRT5_OUT_SEL0
.set B_Key__PRTDSI__OUT_SEL1, CYREG_PRT5_OUT_SEL1
.set B_Key__PRTDSI__SYNC_OUT, CYREG_PRT5_SYNC_OUT
.set B_Key__PS, CYREG_PRT5_PS
.set B_Key__SHIFT, 1
.set B_Key__SLW, CYREG_PRT5_SLW

/* C_Key */
.set C_Key__0__MASK, 0x04
.set C_Key__0__PC, CYREG_PRT5_PC2
.set C_Key__0__PORT, 5
.set C_Key__0__SHIFT, 2
.set C_Key__AG, CYREG_PRT5_AG
.set C_Key__AMUX, CYREG_PRT5_AMUX
.set C_Key__BIE, CYREG_PRT5_BIE
.set C_Key__BIT_MASK, CYREG_PRT5_BIT_MASK
.set C_Key__BYP, CYREG_PRT5_BYP
.set C_Key__CTL, CYREG_PRT5_CTL
.set C_Key__DM0, CYREG_PRT5_DM0
.set C_Key__DM1, CYREG_PRT5_DM1
.set C_Key__DM2, CYREG_PRT5_DM2
.set C_Key__DR, CYREG_PRT5_DR
.set C_Key__INP_DIS, CYREG_PRT5_INP_DIS
.set C_Key__LCD_COM_SEG, CYREG_PRT5_LCD_COM_SEG
.set C_Key__LCD_EN, CYREG_PRT5_LCD_EN
.set C_Key__MASK, 0x04
.set C_Key__PORT, 5
.set C_Key__PRT, CYREG_PRT5_PRT
.set C_Key__PRTDSI__CAPS_SEL, CYREG_PRT5_CAPS_SEL
.set C_Key__PRTDSI__DBL_SYNC_IN, CYREG_PRT5_DBL_SYNC_IN
.set C_Key__PRTDSI__OE_SEL0, CYREG_PRT5_OE_SEL0
.set C_Key__PRTDSI__OE_SEL1, CYREG_PRT5_OE_SEL1
.set C_Key__PRTDSI__OUT_SEL0, CYREG_PRT5_OUT_SEL0
.set C_Key__PRTDSI__OUT_SEL1, CYREG_PRT5_OUT_SEL1
.set C_Key__PRTDSI__SYNC_OUT, CYREG_PRT5_SYNC_OUT
.set C_Key__PS, CYREG_PRT5_PS
.set C_Key__SHIFT, 2
.set C_Key__SLW, CYREG_PRT5_SLW

/* Clock */
.set Clock__CFG0, CYREG_CLKDIST_DCFG0_CFG0
.set Clock__CFG1, CYREG_CLKDIST_DCFG0_CFG1
.set Clock__CFG2, CYREG_CLKDIST_DCFG0_CFG2
.set Clock__CFG2_SRC_SEL_MASK, 0x07
.set Clock__INDEX, 0x00
.set Clock__PM_ACT_CFG, CYREG_PM_ACT_CFG2
.set Clock__PM_ACT_MSK, 0x01
.set Clock__PM_STBY_CFG, CYREG_PM_STBY_CFG2
.set Clock__PM_STBY_MSK, 0x01

/* D_Key */
.set D_Key__0__MASK, 0x08
.set D_Key__0__PC, CYREG_PRT5_PC3
.set D_Key__0__PORT, 5
.set D_Key__0__SHIFT, 3
.set D_Key__AG, CYREG_PRT5_AG
.set D_Key__AMUX, CYREG_PRT5_AMUX
.set D_Key__BIE, CYREG_PRT5_BIE
.set D_Key__BIT_MASK, CYREG_PRT5_BIT_MASK
.set D_Key__BYP, CYREG_PRT5_BYP
.set D_Key__CTL, CYREG_PRT5_CTL
.set D_Key__DM0, CYREG_PRT5_DM0
.set D_Key__DM1, CYREG_PRT5_DM1
.set D_Key__DM2, CYREG_PRT5_DM2
.set D_Key__DR, CYREG_PRT5_DR
.set D_Key__INP_DIS, CYREG_PRT5_INP_DIS
.set D_Key__LCD_COM_SEG, CYREG_PRT5_LCD_COM_SEG
.set D_Key__LCD_EN, CYREG_PRT5_LCD_EN
.set D_Key__MASK, 0x08
.set D_Key__PORT, 5
.set D_Key__PRT, CYREG_PRT5_PRT
.set D_Key__PRTDSI__CAPS_SEL, CYREG_PRT5_CAPS_SEL
.set D_Key__PRTDSI__DBL_SYNC_IN, CYREG_PRT5_DBL_SYNC_IN
.set D_Key__PRTDSI__OE_SEL0, CYREG_PRT5_OE_SEL0
.set D_Key__PRTDSI__OE_SEL1, CYREG_PRT5_OE_SEL1
.set D_Key__PRTDSI__OUT_SEL0, CYREG_PRT5_OUT_SEL0
.set D_Key__PRTDSI__OUT_SEL1, CYREG_PRT5_OUT_SEL1
.set D_Key__PRTDSI__SYNC_OUT, CYREG_PRT5_SYNC_OUT
.set D_Key__PS, CYREG_PRT5_PS
.set D_Key__SHIFT, 3
.set D_Key__SLW, CYREG_PRT5_SLW

/* E_Key */
.set E_Key__0__MASK, 0x10
.set E_Key__0__PC, CYREG_PRT5_PC4
.set E_Key__0__PORT, 5
.set E_Key__0__SHIFT, 4
.set E_Key__AG, CYREG_PRT5_AG
.set E_Key__AMUX, CYREG_PRT5_AMUX
.set E_Key__BIE, CYREG_PRT5_BIE
.set E_Key__BIT_MASK, CYREG_PRT5_BIT_MASK
.set E_Key__BYP, CYREG_PRT5_BYP
.set E_Key__CTL, CYREG_PRT5_CTL
.set E_Key__DM0, CYREG_PRT5_DM0
.set E_Key__DM1, CYREG_PRT5_DM1
.set E_Key__DM2, CYREG_PRT5_DM2
.set E_Key__DR, CYREG_PRT5_DR
.set E_Key__INP_DIS, CYREG_PRT5_INP_DIS
.set E_Key__LCD_COM_SEG, CYREG_PRT5_LCD_COM_SEG
.set E_Key__LCD_EN, CYREG_PRT5_LCD_EN
.set E_Key__MASK, 0x10
.set E_Key__PORT, 5
.set E_Key__PRT, CYREG_PRT5_PRT
.set E_Key__PRTDSI__CAPS_SEL, CYREG_PRT5_CAPS_SEL
.set E_Key__PRTDSI__DBL_SYNC_IN, CYREG_PRT5_DBL_SYNC_IN
.set E_Key__PRTDSI__OE_SEL0, CYREG_PRT5_OE_SEL0
.set E_Key__PRTDSI__OE_SEL1, CYREG_PRT5_OE_SEL1
.set E_Key__PRTDSI__OUT_SEL0, CYREG_PRT5_OUT_SEL0
.set E_Key__PRTDSI__OUT_SEL1, CYREG_PRT5_OUT_SEL1
.set E_Key__PRTDSI__SYNC_OUT, CYREG_PRT5_SYNC_OUT
.set E_Key__PS, CYREG_PRT5_PS
.set E_Key__SHIFT, 4
.set E_Key__SLW, CYREG_PRT5_SLW

/* F_Key */
.set F_Key__0__MASK, 0x20
.set F_Key__0__PC, CYREG_PRT5_PC5
.set F_Key__0__PORT, 5
.set F_Key__0__SHIFT, 5
.set F_Key__AG, CYREG_PRT5_AG
.set F_Key__AMUX, CYREG_PRT5_AMUX
.set F_Key__BIE, CYREG_PRT5_BIE
.set F_Key__BIT_MASK, CYREG_PRT5_BIT_MASK
.set F_Key__BYP, CYREG_PRT5_BYP
.set F_Key__CTL, CYREG_PRT5_CTL
.set F_Key__DM0, CYREG_PRT5_DM0
.set F_Key__DM1, CYREG_PRT5_DM1
.set F_Key__DM2, CYREG_PRT5_DM2
.set F_Key__DR, CYREG_PRT5_DR
.set F_Key__INP_DIS, CYREG_PRT5_INP_DIS
.set F_Key__LCD_COM_SEG, CYREG_PRT5_LCD_COM_SEG
.set F_Key__LCD_EN, CYREG_PRT5_LCD_EN
.set F_Key__MASK, 0x20
.set F_Key__PORT, 5
.set F_Key__PRT, CYREG_PRT5_PRT
.set F_Key__PRTDSI__CAPS_SEL, CYREG_PRT5_CAPS_SEL
.set F_Key__PRTDSI__DBL_SYNC_IN, CYREG_PRT5_DBL_SYNC_IN
.set F_Key__PRTDSI__OE_SEL0, CYREG_PRT5_OE_SEL0
.set F_Key__PRTDSI__OE_SEL1, CYREG_PRT5_OE_SEL1
.set F_Key__PRTDSI__OUT_SEL0, CYREG_PRT5_OUT_SEL0
.set F_Key__PRTDSI__OUT_SEL1, CYREG_PRT5_OUT_SEL1
.set F_Key__PRTDSI__SYNC_OUT, CYREG_PRT5_SYNC_OUT
.set F_Key__PS, CYREG_PRT5_PS
.set F_Key__SHIFT, 5
.set F_Key__SLW, CYREG_PRT5_SLW

/* G_Key */
.set G_Key__0__MASK, 0x40
.set G_Key__0__PC, CYREG_PRT5_PC6
.set G_Key__0__PORT, 5
.set G_Key__0__SHIFT, 6
.set G_Key__AG, CYREG_PRT5_AG
.set G_Key__AMUX, CYREG_PRT5_AMUX
.set G_Key__BIE, CYREG_PRT5_BIE
.set G_Key__BIT_MASK, CYREG_PRT5_BIT_MASK
.set G_Key__BYP, CYREG_PRT5_BYP
.set G_Key__CTL, CYREG_PRT5_CTL
.set G_Key__DM0, CYREG_PRT5_DM0
.set G_Key__DM1, CYREG_PRT5_DM1
.set G_Key__DM2, CYREG_PRT5_DM2
.set G_Key__DR, CYREG_PRT5_DR
.set G_Key__INP_DIS, CYREG_PRT5_INP_DIS
.set G_Key__LCD_COM_SEG, CYREG_PRT5_LCD_COM_SEG
.set G_Key__LCD_EN, CYREG_PRT5_LCD_EN
.set G_Key__MASK, 0x40
.set G_Key__PORT, 5
.set G_Key__PRT, CYREG_PRT5_PRT
.set G_Key__PRTDSI__CAPS_SEL, CYREG_PRT5_CAPS_SEL
.set G_Key__PRTDSI__DBL_SYNC_IN, CYREG_PRT5_DBL_SYNC_IN
.set G_Key__PRTDSI__OE_SEL0, CYREG_PRT5_OE_SEL0
.set G_Key__PRTDSI__OE_SEL1, CYREG_PRT5_OE_SEL1
.set G_Key__PRTDSI__OUT_SEL0, CYREG_PRT5_OUT_SEL0
.set G_Key__PRTDSI__OUT_SEL1, CYREG_PRT5_OUT_SEL1
.set G_Key__PRTDSI__SYNC_OUT, CYREG_PRT5_SYNC_OUT
.set G_Key__PS, CYREG_PRT5_PS
.set G_Key__SHIFT, 6
.set G_Key__SLW, CYREG_PRT5_SLW

/* Pot_A */
.set Pot_A__0__MASK, 0x40
.set Pot_A__0__PC, CYREG_PRT3_PC6
.set Pot_A__0__PORT, 3
.set Pot_A__0__SHIFT, 6
.set Pot_A__AG, CYREG_PRT3_AG
.set Pot_A__AMUX, CYREG_PRT3_AMUX
.set Pot_A__BIE, CYREG_PRT3_BIE
.set Pot_A__BIT_MASK, CYREG_PRT3_BIT_MASK
.set Pot_A__BYP, CYREG_PRT3_BYP
.set Pot_A__CTL, CYREG_PRT3_CTL
.set Pot_A__DM0, CYREG_PRT3_DM0
.set Pot_A__DM1, CYREG_PRT3_DM1
.set Pot_A__DM2, CYREG_PRT3_DM2
.set Pot_A__DR, CYREG_PRT3_DR
.set Pot_A__INP_DIS, CYREG_PRT3_INP_DIS
.set Pot_A__LCD_COM_SEG, CYREG_PRT3_LCD_COM_SEG
.set Pot_A__LCD_EN, CYREG_PRT3_LCD_EN
.set Pot_A__MASK, 0x40
.set Pot_A__PORT, 3
.set Pot_A__PRT, CYREG_PRT3_PRT
.set Pot_A__PRTDSI__CAPS_SEL, CYREG_PRT3_CAPS_SEL
.set Pot_A__PRTDSI__DBL_SYNC_IN, CYREG_PRT3_DBL_SYNC_IN
.set Pot_A__PRTDSI__OE_SEL0, CYREG_PRT3_OE_SEL0
.set Pot_A__PRTDSI__OE_SEL1, CYREG_PRT3_OE_SEL1
.set Pot_A__PRTDSI__OUT_SEL0, CYREG_PRT3_OUT_SEL0
.set Pot_A__PRTDSI__OUT_SEL1, CYREG_PRT3_OUT_SEL1
.set Pot_A__PRTDSI__SYNC_OUT, CYREG_PRT3_SYNC_OUT
.set Pot_A__PS, CYREG_PRT3_PS
.set Pot_A__SHIFT, 6
.set Pot_A__SLW, CYREG_PRT3_SLW

/* Pot_B */
.set Pot_B__0__MASK, 0x80
.set Pot_B__0__PC, CYREG_PRT3_PC7
.set Pot_B__0__PORT, 3
.set Pot_B__0__SHIFT, 7
.set Pot_B__AG, CYREG_PRT3_AG
.set Pot_B__AMUX, CYREG_PRT3_AMUX
.set Pot_B__BIE, CYREG_PRT3_BIE
.set Pot_B__BIT_MASK, CYREG_PRT3_BIT_MASK
.set Pot_B__BYP, CYREG_PRT3_BYP
.set Pot_B__CTL, CYREG_PRT3_CTL
.set Pot_B__DM0, CYREG_PRT3_DM0
.set Pot_B__DM1, CYREG_PRT3_DM1
.set Pot_B__DM2, CYREG_PRT3_DM2
.set Pot_B__DR, CYREG_PRT3_DR
.set Pot_B__INP_DIS, CYREG_PRT3_INP_DIS
.set Pot_B__LCD_COM_SEG, CYREG_PRT3_LCD_COM_SEG
.set Pot_B__LCD_EN, CYREG_PRT3_LCD_EN
.set Pot_B__MASK, 0x80
.set Pot_B__PORT, 3
.set Pot_B__PRT, CYREG_PRT3_PRT
.set Pot_B__PRTDSI__CAPS_SEL, CYREG_PRT3_CAPS_SEL
.set Pot_B__PRTDSI__DBL_SYNC_IN, CYREG_PRT3_DBL_SYNC_IN
.set Pot_B__PRTDSI__OE_SEL0, CYREG_PRT3_OE_SEL0
.set Pot_B__PRTDSI__OE_SEL1, CYREG_PRT3_OE_SEL1
.set Pot_B__PRTDSI__OUT_SEL0, CYREG_PRT3_OUT_SEL0
.set Pot_B__PRTDSI__OUT_SEL1, CYREG_PRT3_OUT_SEL1
.set Pot_B__PRTDSI__SYNC_OUT, CYREG_PRT3_SYNC_OUT
.set Pot_B__PS, CYREG_PRT3_PS
.set Pot_B__SHIFT, 7
.set Pot_B__SLW, CYREG_PRT3_SLW

/* A2_Key */
.set A2_Key__0__MASK, 0x80
.set A2_Key__0__PC, CYREG_PRT5_PC7
.set A2_Key__0__PORT, 5
.set A2_Key__0__SHIFT, 7
.set A2_Key__AG, CYREG_PRT5_AG
.set A2_Key__AMUX, CYREG_PRT5_AMUX
.set A2_Key__BIE, CYREG_PRT5_BIE
.set A2_Key__BIT_MASK, CYREG_PRT5_BIT_MASK
.set A2_Key__BYP, CYREG_PRT5_BYP
.set A2_Key__CTL, CYREG_PRT5_CTL
.set A2_Key__DM0, CYREG_PRT5_DM0
.set A2_Key__DM1, CYREG_PRT5_DM1
.set A2_Key__DM2, CYREG_PRT5_DM2
.set A2_Key__DR, CYREG_PRT5_DR
.set A2_Key__INP_DIS, CYREG_PRT5_INP_DIS
.set A2_Key__LCD_COM_SEG, CYREG_PRT5_LCD_COM_SEG
.set A2_Key__LCD_EN, CYREG_PRT5_LCD_EN
.set A2_Key__MASK, 0x80
.set A2_Key__PORT, 5
.set A2_Key__PRT, CYREG_PRT5_PRT
.set A2_Key__PRTDSI__CAPS_SEL, CYREG_PRT5_CAPS_SEL
.set A2_Key__PRTDSI__DBL_SYNC_IN, CYREG_PRT5_DBL_SYNC_IN
.set A2_Key__PRTDSI__OE_SEL0, CYREG_PRT5_OE_SEL0
.set A2_Key__PRTDSI__OE_SEL1, CYREG_PRT5_OE_SEL1
.set A2_Key__PRTDSI__OUT_SEL0, CYREG_PRT5_OUT_SEL0
.set A2_Key__PRTDSI__OUT_SEL1, CYREG_PRT5_OUT_SEL1
.set A2_Key__PRTDSI__SYNC_OUT, CYREG_PRT5_SYNC_OUT
.set A2_Key__PS, CYREG_PRT5_PS
.set A2_Key__SHIFT, 7
.set A2_Key__SLW, CYREG_PRT5_SLW

/* Audio_out */
.set Audio_out__0__MASK, 0x02
.set Audio_out__0__PC, CYREG_PRT4_PC1
.set Audio_out__0__PORT, 4
.set Audio_out__0__SHIFT, 1
.set Audio_out__AG, CYREG_PRT4_AG
.set Audio_out__AMUX, CYREG_PRT4_AMUX
.set Audio_out__BIE, CYREG_PRT4_BIE
.set Audio_out__BIT_MASK, CYREG_PRT4_BIT_MASK
.set Audio_out__BYP, CYREG_PRT4_BYP
.set Audio_out__CTL, CYREG_PRT4_CTL
.set Audio_out__DM0, CYREG_PRT4_DM0
.set Audio_out__DM1, CYREG_PRT4_DM1
.set Audio_out__DM2, CYREG_PRT4_DM2
.set Audio_out__DR, CYREG_PRT4_DR
.set Audio_out__INP_DIS, CYREG_PRT4_INP_DIS
.set Audio_out__LCD_COM_SEG, CYREG_PRT4_LCD_COM_SEG
.set Audio_out__LCD_EN, CYREG_PRT4_LCD_EN
.set Audio_out__MASK, 0x02
.set Audio_out__PORT, 4
.set Audio_out__PRT, CYREG_PRT4_PRT
.set Audio_out__PRTDSI__CAPS_SEL, CYREG_PRT4_CAPS_SEL
.set Audio_out__PRTDSI__DBL_SYNC_IN, CYREG_PRT4_DBL_SYNC_IN
.set Audio_out__PRTDSI__OE_SEL0, CYREG_PRT4_OE_SEL0
.set Audio_out__PRTDSI__OE_SEL1, CYREG_PRT4_OE_SEL1
.set Audio_out__PRTDSI__OUT_SEL0, CYREG_PRT4_OUT_SEL0
.set Audio_out__PRTDSI__OUT_SEL1, CYREG_PRT4_OUT_SEL1
.set Audio_out__PRTDSI__SYNC_OUT, CYREG_PRT4_SYNC_OUT
.set Audio_out__PS, CYREG_PRT4_PS
.set Audio_out__SHIFT, 1
.set Audio_out__SLW, CYREG_PRT4_SLW

/* Status_Reg */
.set Status_Reg_sts_sts_reg__0__MASK, 0x01
.set Status_Reg_sts_sts_reg__0__POS, 0
.set Status_Reg_sts_sts_reg__1__MASK, 0x02
.set Status_Reg_sts_sts_reg__1__POS, 1
.set Status_Reg_sts_sts_reg__16BIT_STATUS_AUX_CTL_REG, CYREG_B0_UDB10_11_ACTL
.set Status_Reg_sts_sts_reg__16BIT_STATUS_REG, CYREG_B0_UDB10_11_ST
.set Status_Reg_sts_sts_reg__2__MASK, 0x04
.set Status_Reg_sts_sts_reg__2__POS, 2
.set Status_Reg_sts_sts_reg__3__MASK, 0x08
.set Status_Reg_sts_sts_reg__3__POS, 3
.set Status_Reg_sts_sts_reg__4__MASK, 0x10
.set Status_Reg_sts_sts_reg__4__POS, 4
.set Status_Reg_sts_sts_reg__5__MASK, 0x20
.set Status_Reg_sts_sts_reg__5__POS, 5
.set Status_Reg_sts_sts_reg__6__MASK, 0x40
.set Status_Reg_sts_sts_reg__6__POS, 6
.set Status_Reg_sts_sts_reg__7__MASK, 0x80
.set Status_Reg_sts_sts_reg__7__POS, 7
.set Status_Reg_sts_sts_reg__MASK, 0xFF
.set Status_Reg_sts_sts_reg__MASK_REG, CYREG_B0_UDB10_MSK
.set Status_Reg_sts_sts_reg__MASK_ST_AUX_CTL_REG, CYREG_B0_UDB10_MSK_ACTL
.set Status_Reg_sts_sts_reg__PER_ST_AUX_CTL_REG, CYREG_B0_UDB10_MSK_ACTL
.set Status_Reg_sts_sts_reg__STATUS_AUX_CTL_REG, CYREG_B0_UDB10_ACTL
.set Status_Reg_sts_sts_reg__STATUS_CNT_REG, CYREG_B0_UDB10_ST_CTL
.set Status_Reg_sts_sts_reg__STATUS_CONTROL_REG, CYREG_B0_UDB10_ST_CTL
.set Status_Reg_sts_sts_reg__STATUS_REG, CYREG_B0_UDB10_ST

/* Control_Reg */
.set Control_Reg_Sync_ctrl_reg__0__MASK, 0x01
.set Control_Reg_Sync_ctrl_reg__0__POS, 0
.set Control_Reg_Sync_ctrl_reg__1__MASK, 0x02
.set Control_Reg_Sync_ctrl_reg__1__POS, 1
.set Control_Reg_Sync_ctrl_reg__16BIT_CONTROL_AUX_CTL_REG, CYREG_B0_UDB10_11_ACTL
.set Control_Reg_Sync_ctrl_reg__16BIT_CONTROL_CONTROL_REG, CYREG_B0_UDB10_11_CTL
.set Control_Reg_Sync_ctrl_reg__16BIT_CONTROL_COUNT_REG, CYREG_B0_UDB10_11_CTL
.set Control_Reg_Sync_ctrl_reg__16BIT_COUNT_CONTROL_REG, CYREG_B0_UDB10_11_CTL
.set Control_Reg_Sync_ctrl_reg__16BIT_COUNT_COUNT_REG, CYREG_B0_UDB10_11_CTL
.set Control_Reg_Sync_ctrl_reg__16BIT_MASK_MASK_REG, CYREG_B0_UDB10_11_MSK
.set Control_Reg_Sync_ctrl_reg__16BIT_MASK_PERIOD_REG, CYREG_B0_UDB10_11_MSK
.set Control_Reg_Sync_ctrl_reg__16BIT_PERIOD_MASK_REG, CYREG_B0_UDB10_11_MSK
.set Control_Reg_Sync_ctrl_reg__16BIT_PERIOD_PERIOD_REG, CYREG_B0_UDB10_11_MSK
.set Control_Reg_Sync_ctrl_reg__2__MASK, 0x04
.set Control_Reg_Sync_ctrl_reg__2__POS, 2
.set Control_Reg_Sync_ctrl_reg__3__MASK, 0x08
.set Control_Reg_Sync_ctrl_reg__3__POS, 3
.set Control_Reg_Sync_ctrl_reg__CONTROL_AUX_CTL_REG, CYREG_B0_UDB10_ACTL
.set Control_Reg_Sync_ctrl_reg__CONTROL_REG, CYREG_B0_UDB10_CTL
.set Control_Reg_Sync_ctrl_reg__CONTROL_ST_REG, CYREG_B0_UDB10_ST_CTL
.set Control_Reg_Sync_ctrl_reg__COUNT_REG, CYREG_B0_UDB10_CTL
.set Control_Reg_Sync_ctrl_reg__COUNT_ST_REG, CYREG_B0_UDB10_ST_CTL
.set Control_Reg_Sync_ctrl_reg__MASK, 0x0F
.set Control_Reg_Sync_ctrl_reg__MASK_CTL_AUX_CTL_REG, CYREG_B0_UDB10_MSK_ACTL
.set Control_Reg_Sync_ctrl_reg__PER_CTL_AUX_CTL_REG, CYREG_B0_UDB10_MSK_ACTL
.set Control_Reg_Sync_ctrl_reg__PERIOD_REG, CYREG_B0_UDB10_MSK

/* Miscellaneous */
.set BCLK__BUS_CLK__HZ, 24000000
.set BCLK__BUS_CLK__KHZ, 24000
.set BCLK__BUS_CLK__MHZ, 24
.set CYDEV_CHIP_DIE_GEN4, 2
.set CYDEV_CHIP_DIE_LEOPARD, 1
.set CYDEV_CHIP_DIE_PANTHER, 12
.set CYDEV_CHIP_DIE_PSOC4A, 5
.set CYDEV_CHIP_DIE_PSOC5LP, 11
.set CYDEV_CHIP_DIE_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_PSOC3, 1
.set CYDEV_CHIP_FAMILY_PSOC4, 2
.set CYDEV_CHIP_FAMILY_PSOC5, 3
.set CYDEV_CHIP_FAMILY_UNKNOWN, 0
.set CYDEV_CHIP_FAMILY_USED, CYDEV_CHIP_FAMILY_PSOC5
.set CYDEV_CHIP_JTAG_ID, 0x2E160069
.set CYDEV_CHIP_MEMBER_3A, 1
.set CYDEV_CHIP_MEMBER_4A, 5
.set CYDEV_CHIP_MEMBER_4C, 9
.set CYDEV_CHIP_MEMBER_4D, 3
.set CYDEV_CHIP_MEMBER_4E, 4
.set CYDEV_CHIP_MEMBER_4F, 6
.set CYDEV_CHIP_MEMBER_4G, 2
.set CYDEV_CHIP_MEMBER_4L, 8
.set CYDEV_CHIP_MEMBER_4M, 7
.set CYDEV_CHIP_MEMBER_5A, 11
.set CYDEV_CHIP_MEMBER_5B, 10
.set CYDEV_CHIP_MEMBER_UNKNOWN, 0
.set CYDEV_CHIP_MEMBER_USED, CYDEV_CHIP_MEMBER_5B
.set CYDEV_CHIP_DIE_EXPECT, CYDEV_CHIP_MEMBER_USED
.set CYDEV_CHIP_DIE_ACTUAL, CYDEV_CHIP_DIE_EXPECT
.set CYDEV_CHIP_REV_GEN4_ES, 17
.set CYDEV_CHIP_REV_GEN4_ES2, 33
.set CYDEV_CHIP_REV_GEN4_PRODUCTION, 17
.set CYDEV_CHIP_REV_LEOPARD_ES1, 0
.set CYDEV_CHIP_REV_LEOPARD_ES2, 1
.set CYDEV_CHIP_REV_LEOPARD_ES3, 3
.set CYDEV_CHIP_REV_LEOPARD_PRODUCTION, 3
.set CYDEV_CHIP_REV_PANTHER_ES0, 0
.set CYDEV_CHIP_REV_PANTHER_ES1, 1
.set CYDEV_CHIP_REV_PANTHER_PRODUCTION, 1
.set CYDEV_CHIP_REV_PSOC4A_ES0, 17
.set CYDEV_CHIP_REV_PSOC4A_PRODUCTION, 17
.set CYDEV_CHIP_REV_PSOC5LP_ES0, 0
.set CYDEV_CHIP_REV_PSOC5LP_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_3A_ES1, 0
.set CYDEV_CHIP_REVISION_3A_ES2, 1
.set CYDEV_CHIP_REVISION_3A_ES3, 3
.set CYDEV_CHIP_REVISION_3A_PRODUCTION, 3
.set CYDEV_CHIP_REVISION_4A_ES0, 17
.set CYDEV_CHIP_REVISION_4A_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4C_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4D_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4E_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4F_PRODUCTION_256K, 0
.set CYDEV_CHIP_REVISION_4G_ES, 17
.set CYDEV_CHIP_REVISION_4G_ES2, 33
.set CYDEV_CHIP_REVISION_4G_PRODUCTION, 17
.set CYDEV_CHIP_REVISION_4L_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_4M_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_5A_ES0, 0
.set CYDEV_CHIP_REVISION_5A_ES1, 1
.set CYDEV_CHIP_REVISION_5A_PRODUCTION, 1
.set CYDEV_CHIP_REVISION_5B_ES0, 0
.set CYDEV_CHIP_REVISION_5B_PRODUCTION, 0
.set CYDEV_CHIP_REVISION_USED, CYDEV_CHIP_REVISION_5B_PRODUCTION
.set CYDEV_CHIP_REV_EXPECT, CYDEV_CHIP_REVISION_USED
.set CYDEV_CONFIG_FASTBOOT_ENABLED, 1
.set CYDEV_CONFIG_UNUSED_IO_AllowButWarn, 0
.set CYDEV_CONFIG_UNUSED_IO, CYDEV_CONFIG_UNUSED_IO_AllowButWarn
.set CYDEV_CONFIG_UNUSED_IO_AllowWithInfo, 1
.set CYDEV_CONFIG_UNUSED_IO_Disallowed, 2
.set CYDEV_CONFIGURATION_COMPRESSED, 1
.set CYDEV_CONFIGURATION_DMA, 0
.set CYDEV_CONFIGURATION_ECC, 1
.set CYDEV_CONFIGURATION_IMOENABLED, CYDEV_CONFIG_FASTBOOT_ENABLED
.set CYDEV_CONFIGURATION_MODE_COMPRESSED, 0
.set CYDEV_CONFIGURATION_MODE, CYDEV_CONFIGURATION_MODE_COMPRESSED
.set CYDEV_CONFIGURATION_MODE_DMA, 2
.set CYDEV_CONFIGURATION_MODE_UNCOMPRESSED, 1
.set CYDEV_DEBUG_ENABLE_MASK, 0x20
.set CYDEV_DEBUG_ENABLE_REGISTER, CYREG_MLOGIC_DEBUG
.set CYDEV_DEBUGGING_DPS_Disable, 3
.set CYDEV_DEBUGGING_DPS_JTAG_4, 1
.set CYDEV_DEBUGGING_DPS_JTAG_5, 0
.set CYDEV_DEBUGGING_DPS_SWD, 2
.set CYDEV_DEBUGGING_DPS_SWD_SWV, 6
.set CYDEV_DEBUGGING_DPS, CYDEV_DEBUGGING_DPS_SWD_SWV
.set CYDEV_DEBUGGING_ENABLE, 1
.set CYDEV_DEBUGGING_XRES, 0
.set CYDEV_DMA_CHANNELS_AVAILABLE, 24
.set CYDEV_ECC_ENABLE, 0
.set CYDEV_HEAP_SIZE, 0x80
.set CYDEV_INSTRUCT_CACHE_ENABLED, 1
.set CYDEV_INTR_RISING, 0x00000001
.set CYDEV_PROJ_TYPE, 0
.set CYDEV_PROJ_TYPE_BOOTLOADER, 1
.set CYDEV_PROJ_TYPE_LAUNCHER, 5
.set CYDEV_PROJ_TYPE_LOADABLE, 2
.set CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER, 4
.set CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER, 3
.set CYDEV_PROJ_TYPE_STANDARD, 0
.set CYDEV_PROTECTION_ENABLE, 0
.set CYDEV_STACK_SIZE, 0x0800
.set CYDEV_USE_BUNDLED_CMSIS, 1
.set CYDEV_VARIABLE_VDDA, 0
.set CYDEV_VDDA_MV, 5000
.set CYDEV_VDDD_MV, 5000
.set CYDEV_VDDIO0_MV, 5000
.set CYDEV_VDDIO1_MV, 5000
.set CYDEV_VDDIO2_MV, 5000
.set CYDEV_VDDIO3_MV, 5000
.set CYDEV_VIO0_MV, 5000
.set CYDEV_VIO1_MV, 5000
.set CYDEV_VIO2_MV, 5000
.set CYDEV_VIO3_MV, 5000
.set CYIPBLOCK_ARM_CM3_VERSION, 0
.set CYIPBLOCK_P3_ANAIF_VERSION, 0
.set CYIPBLOCK_P3_CAN_VERSION, 0
.set CYIPBLOCK_P3_CAPSENSE_VERSION, 0
.set CYIPBLOCK_P3_COMP_VERSION, 0
.set CYIPBLOCK_P3_DECIMATOR_VERSION, 0
.set CYIPBLOCK_P3_DFB_VERSION, 0
.set CYIPBLOCK_P3_DMA_VERSION, 0
.set CYIPBLOCK_P3_DRQ_VERSION, 0
.set CYIPBLOCK_P3_DSM_VERSION, 0
.set CYIPBLOCK_P3_EMIF_VERSION, 0
.set CYIPBLOCK_P3_I2C_VERSION, 0
.set CYIPBLOCK_P3_LCD_VERSION, 0
.set CYIPBLOCK_P3_LPF_VERSION, 0
.set CYIPBLOCK_P3_OPAMP_VERSION, 0
.set CYIPBLOCK_P3_PM_VERSION, 0
.set CYIPBLOCK_P3_SCCT_VERSION, 0
.set CYIPBLOCK_P3_TIMER_VERSION, 0
.set CYIPBLOCK_P3_USB_VERSION, 0
.set CYIPBLOCK_P3_VIDAC_VERSION, 0
.set CYIPBLOCK_P3_VREF_VERSION, 0
.set CYIPBLOCK_S8_GPIO_VERSION, 0
.set CYIPBLOCK_S8_IRQ_VERSION, 0
.set CYIPBLOCK_S8_SAR_VERSION, 0
.set CYIPBLOCK_S8_SIO_VERSION, 0
.set CYIPBLOCK_S8_UDB_VERSION, 0
.set DMA_CHANNELS_USED__MASK0, 0x000000FF
.set CYDEV_BOOTLOADER_ENABLE, 0
.endif
