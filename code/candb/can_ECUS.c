#include "can_ECUS.h"
#include <string.h>

CAN_msg_status_t ECUA_Status_status;
ECUA_Status_t ECUA_Status_data;
CAN_msg_status_t ECUA_Limits_status;
ECUA_Limits_t ECUA_Limits_data;
CAN_msg_status_t ECUA_ACPMeas_status;
ECUA_ACPMeas_t ECUA_ACPMeas_data;
CAN_msg_status_t ECUA_Estimation_status;
ECUA_Estimation_t ECUA_Estimation_data;
CAN_msg_status_t ECUA_AMSOverall_status;
ECUA_AMSOverall_t ECUA_AMSOverall_data;
CAN_msg_status_t ECUB_Status_status;
ECUB_Status_t ECUB_Status_data;
CAN_msg_status_t ECUB_Cooling_status;
ECUB_Cooling_t ECUB_Cooling_data;
CAN_msg_status_t ECUB_TEMPSuspR_status;
ECUB_TEMPSuspR_t ECUB_TEMPSuspR_data;
CAN_msg_status_t ECUB_TEMPAux_status;
ECUB_TEMPAux_t ECUB_TEMPAux_data;
CAN_msg_status_t ECUF_Status_status;
ECUF_Status_t ECUF_Status_data;
CAN_msg_status_t ECUF_STW_status;
ECUF_STW_t ECUF_STW_data;
CAN_msg_status_t ECUF_TEMPSuspF_status;
ECUF_TEMPSuspF_t ECUF_TEMPSuspF_data;
CAN_msg_status_t ECUP_Status_status;
ECUP_Status_t ECUP_Status_data;
CAN_msg_status_t ECUP_Pedals_status;
ECUP_Pedals_t ECUP_Pedals_data;
CAN_msg_status_t ECUP_Pressure_status;
ECUP_Pressure_t ECUP_Pressure_data;
CAN_msg_status_t ECUP_DiagPos_status;
ECUP_DiagPos_t ECUP_DiagPos_data;
int32_t ECUS_Status_last_sent;
CAN_msg_status_t IMU_Status_status;
IMU_Status_t IMU_Status_data;
CAN_msg_status_t MCR_GeneralReport_status;
MCR_GeneralReport_t MCR_GeneralReport_data;
CAN_msg_status_t MCR_ThermalMeasuresA_status;
MCR_ThermalMeasuresA_t MCR_ThermalMeasuresA_data;
CAN_msg_status_t MCR_ThermalMeasuresB_status;
MCR_ThermalMeasuresB_t MCR_ThermalMeasuresB_data;
CAN_msg_status_t VDCU_Status_status;
VDCU_Status_t VDCU_Status_data;
CAN_msg_status_t VDCU_Controller_status;
VDCU_Controller_t VDCU_Controller_data;
CAN_msg_status_t VDCU_Body_status;
VDCU_Body_t VDCU_Body_data;
CAN_msg_status_t VDCU_WheelFz_status;
VDCU_WheelFz_t VDCU_WheelFz_data;
int32_t VDCU_Param_last_sent;
CAN_msg_status_t VDCU_Param_ACK_status;
VDCU_Param_ACK_t VDCU_Param_ACK_data;
CAN_msg_status_t VDCU_SOC_status;
VDCU_SOC_t VDCU_SOC_data;

void candbInit(void) {
    canInitMsgStatus(&ECUA_Status_status, 500);
    canInitMsgStatus(&ECUA_Limits_status, 500);
    canInitMsgStatus(&ECUA_ACPMeas_status, 100);
    canInitMsgStatus(&ECUA_Estimation_status, 500);
    canInitMsgStatus(&ECUA_AMSOverall_status, -1);
    canInitMsgStatus(&ECUB_Status_status, 1000);
    canInitMsgStatus(&ECUB_Cooling_status, -1);
    canInitMsgStatus(&ECUB_TEMPSuspR_status, -1);
    canInitMsgStatus(&ECUB_TEMPAux_status, -1);
    canInitMsgStatus(&ECUF_Status_status, 1000);
    canInitMsgStatus(&ECUF_STW_status, 50);
    canInitMsgStatus(&ECUF_TEMPSuspF_status, -1);
    canInitMsgStatus(&ECUP_Status_status, 500);
    canInitMsgStatus(&ECUP_Pedals_status, 50);
    canInitMsgStatus(&ECUP_Pressure_status, -1);
    canInitMsgStatus(&ECUP_DiagPos_status, 250);
    ECUS_Status_last_sent = -1;
    canInitMsgStatus(&IMU_Status_status, 1000);
    canInitMsgStatus(&MCR_GeneralReport_status, -1);
    canInitMsgStatus(&MCR_ThermalMeasuresA_status, -1);
    canInitMsgStatus(&MCR_ThermalMeasuresB_status, -1);
    canInitMsgStatus(&VDCU_Status_status, 500);
    canInitMsgStatus(&VDCU_Controller_status, 50);
    canInitMsgStatus(&VDCU_Body_status, 50);
    canInitMsgStatus(&VDCU_WheelFz_status, 50);
    VDCU_Param_last_sent = -1;
    canInitMsgStatus(&VDCU_Param_ACK_status, 20);
    canInitMsgStatus(&VDCU_SOC_status, 50);
}

int ECUA_decode_Status_s(const uint8_t* bytes, size_t length, ECUA_Status_t* data_out) {
    if (length < 7)
        return 0;

    data_out->SDC_IN_Open = (bytes[0] & 0x01);
    data_out->SDC_HV_ILOCK = ((bytes[0] >> 1) & 0x01);
    data_out->SDC_IMD = ((bytes[0] >> 2) & 0x01);
    data_out->SDC_AMS = ((bytes[0] >> 3) & 0x01);
    data_out->SDC_OUT = ((bytes[0] >> 4) & 0x01);
    data_out->SDC_END = ((bytes[0] >> 5) & 0x01);
    data_out->LATCH_SDC_AMS = ((bytes[0] >> 7) & 0x01);
    data_out->AIRsState = (enum ECUA_AIRsState) ((bytes[1] & 0x0F));
    data_out->AIRs_errno = bytes[2];
    data_out->FT_ACP_OT = (bytes[3] & 0x01);
    data_out->FT_AIRS = ((bytes[3] >> 1) & 0x01);
    data_out->FT_DCDC = ((bytes[3] >> 2) & 0x01);
    data_out->FT_FAN1 = ((bytes[3] >> 3) & 0x01);
    data_out->FT_FAN2 = ((bytes[3] >> 4) & 0x01);
    data_out->FT_FAN3 = ((bytes[3] >> 5) & 0x01);
    data_out->FT_HV_OV = ((bytes[3] >> 6) & 0x01);
    data_out->FT_HV_UV = ((bytes[3] >> 7) & 0x01);
    data_out->FT_GLV_UV = (bytes[4] & 0x01);
    data_out->FT_GLV_OV = ((bytes[4] >> 1) & 0x01);
    data_out->FT_AMS = ((bytes[4] >> 2) & 0x01);
    data_out->FT_ANY = ((bytes[4] >> 3) & 0x01);
    data_out->WARN_TEMP_Cell = (bytes[5] & 0x01);
    data_out->WARN_TEMP_DCDC = ((bytes[5] >> 1) & 0x01);
    data_out->WARN_TEMP_Bal = ((bytes[5] >> 2) & 0x01);
    data_out->charger_attached = ((bytes[5] >> 5) & 0x01);
    data_out->DCDC_GLV_EN = ((bytes[5] >> 6) & 0x01);
    data_out->FANS_EN = ((bytes[5] >> 7) & 0x01);
    data_out->SEQ = ((bytes[6] >> 4) & 0x0F);
    return 1;
}

int ECUA_decode_Status(const uint8_t* bytes, size_t length, uint8_t* SDC_IN_Open_out, uint8_t* SDC_HV_ILOCK_out, uint8_t* SDC_IMD_out, uint8_t* SDC_AMS_out, uint8_t* SDC_OUT_out, uint8_t* SDC_END_out, uint8_t* LATCH_SDC_AMS_out, enum ECUA_AIRsState* AIRsState_out, uint8_t* AIRs_errno_out, uint8_t* FT_ACP_OT_out, uint8_t* FT_AIRS_out, uint8_t* FT_DCDC_out, uint8_t* FT_FAN1_out, uint8_t* FT_FAN2_out, uint8_t* FT_FAN3_out, uint8_t* FT_HV_OV_out, uint8_t* FT_HV_UV_out, uint8_t* FT_GLV_UV_out, uint8_t* FT_GLV_OV_out, uint8_t* FT_AMS_out, uint8_t* FT_ANY_out, uint8_t* WARN_TEMP_Cell_out, uint8_t* WARN_TEMP_DCDC_out, uint8_t* WARN_TEMP_Bal_out, uint8_t* charger_attached_out, uint8_t* DCDC_GLV_EN_out, uint8_t* FANS_EN_out, uint8_t* SEQ_out) {
    if (length < 7)
        return 0;

    *SDC_IN_Open_out = (bytes[0] & 0x01);
    *SDC_HV_ILOCK_out = ((bytes[0] >> 1) & 0x01);
    *SDC_IMD_out = ((bytes[0] >> 2) & 0x01);
    *SDC_AMS_out = ((bytes[0] >> 3) & 0x01);
    *SDC_OUT_out = ((bytes[0] >> 4) & 0x01);
    *SDC_END_out = ((bytes[0] >> 5) & 0x01);
    *LATCH_SDC_AMS_out = ((bytes[0] >> 7) & 0x01);
    *AIRsState_out = (enum ECUA_AIRsState) ((bytes[1] & 0x0F));
    *AIRs_errno_out = bytes[2];
    *FT_ACP_OT_out = (bytes[3] & 0x01);
    *FT_AIRS_out = ((bytes[3] >> 1) & 0x01);
    *FT_DCDC_out = ((bytes[3] >> 2) & 0x01);
    *FT_FAN1_out = ((bytes[3] >> 3) & 0x01);
    *FT_FAN2_out = ((bytes[3] >> 4) & 0x01);
    *FT_FAN3_out = ((bytes[3] >> 5) & 0x01);
    *FT_HV_OV_out = ((bytes[3] >> 6) & 0x01);
    *FT_HV_UV_out = ((bytes[3] >> 7) & 0x01);
    *FT_GLV_UV_out = (bytes[4] & 0x01);
    *FT_GLV_OV_out = ((bytes[4] >> 1) & 0x01);
    *FT_AMS_out = ((bytes[4] >> 2) & 0x01);
    *FT_ANY_out = ((bytes[4] >> 3) & 0x01);
    *WARN_TEMP_Cell_out = (bytes[5] & 0x01);
    *WARN_TEMP_DCDC_out = ((bytes[5] >> 1) & 0x01);
    *WARN_TEMP_Bal_out = ((bytes[5] >> 2) & 0x01);
    *charger_attached_out = ((bytes[5] >> 5) & 0x01);
    *DCDC_GLV_EN_out = ((bytes[5] >> 6) & 0x01);
    *FANS_EN_out = ((bytes[5] >> 7) & 0x01);
    *SEQ_out = ((bytes[6] >> 4) & 0x0F);
    return 1;
}

int ECUA_get_Status(ECUA_Status_t* data_out) {
    if (!(ECUA_Status_status.flags & CAN_MSG_RECEIVED))
        return 0;

#ifndef CANDB_IGNORE_TIMEOUTS
    if (txGetTimeMillis() > ECUA_Status_status.timestamp + ECUA_Status_timeout)
        return 0;
#endif

    if (data_out)
        memcpy(data_out, &ECUA_Status_data, sizeof(ECUA_Status_t));

    int flags = ECUA_Status_status.flags;
    ECUA_Status_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void ECUA_Status_on_receive(int (*callback)(ECUA_Status_t* data)) {
    ECUA_Status_status.on_receive = (void (*)(void)) callback;
}

int ECUA_decode_Limits_s(const uint8_t* bytes, size_t length, ECUA_Limits_t* data_out) {
    if (length < 4)
        return 0;

    data_out->PWR_OUT = bytes[0] | bytes[1] << 8;
    data_out->PWR_IN = bytes[2] | bytes[3] << 8;
    return 1;
}

int ECUA_decode_Limits(const uint8_t* bytes, size_t length, uint16_t* PWR_OUT_out, uint16_t* PWR_IN_out) {
    if (length < 4)
        return 0;

    *PWR_OUT_out = bytes[0] | bytes[1] << 8;
    *PWR_IN_out = bytes[2] | bytes[3] << 8;
    return 1;
}

int ECUA_get_Limits(ECUA_Limits_t* data_out) {
    if (!(ECUA_Limits_status.flags & CAN_MSG_RECEIVED))
        return 0;

#ifndef CANDB_IGNORE_TIMEOUTS
    if (txGetTimeMillis() > ECUA_Limits_status.timestamp + ECUA_Limits_timeout)
        return 0;
#endif

    if (data_out)
        memcpy(data_out, &ECUA_Limits_data, sizeof(ECUA_Limits_t));

    int flags = ECUA_Limits_status.flags;
    ECUA_Limits_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void ECUA_Limits_on_receive(int (*callback)(ECUA_Limits_t* data)) {
    ECUA_Limits_status.on_receive = (void (*)(void)) callback;
}

int ECUA_decode_ACPMeas_s(const uint8_t* bytes, size_t length, ECUA_ACPMeas_t* data_out) {
    if (length < 8)
        return 0;

    data_out->Volt_HV_in = bytes[0] | bytes[1] << 8;
    data_out->Volt_HV_out = bytes[2] | bytes[3] << 8;
    data_out->Curr_HV_out = bytes[4] | bytes[5] << 8;
    data_out->Curr_DCDC_out = bytes[6];
    data_out->Curr_FANS = bytes[7];
    return 1;
}

int ECUA_decode_ACPMeas(const uint8_t* bytes, size_t length, uint16_t* Volt_HV_in_out, uint16_t* Volt_HV_out_out, uint16_t* Curr_HV_out_out, uint8_t* Curr_DCDC_out_out, uint8_t* Curr_FANS_out) {
    if (length < 8)
        return 0;

    *Volt_HV_in_out = bytes[0] | bytes[1] << 8;
    *Volt_HV_out_out = bytes[2] | bytes[3] << 8;
    *Curr_HV_out_out = bytes[4] | bytes[5] << 8;
    *Curr_DCDC_out_out = bytes[6];
    *Curr_FANS_out = bytes[7];
    return 1;
}

int ECUA_get_ACPMeas(ECUA_ACPMeas_t* data_out) {
    if (!(ECUA_ACPMeas_status.flags & CAN_MSG_RECEIVED))
        return 0;

#ifndef CANDB_IGNORE_TIMEOUTS
    if (txGetTimeMillis() > ECUA_ACPMeas_status.timestamp + ECUA_ACPMeas_timeout)
        return 0;
#endif

    if (data_out)
        memcpy(data_out, &ECUA_ACPMeas_data, sizeof(ECUA_ACPMeas_t));

    int flags = ECUA_ACPMeas_status.flags;
    ECUA_ACPMeas_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void ECUA_ACPMeas_on_receive(int (*callback)(ECUA_ACPMeas_t* data)) {
    ECUA_ACPMeas_status.on_receive = (void (*)(void)) callback;
}

int ECUA_decode_Estimation_s(const uint8_t* bytes, size_t length, ECUA_Estimation_t* data_out) {
    if (length < 5)
        return 0;

    data_out->Charge_OUT = bytes[0] | bytes[1] << 8;
    data_out->Charge_IN = bytes[2] | bytes[3] << 8;
    data_out->SOC = bytes[4];
    return 1;
}

int ECUA_decode_Estimation(const uint8_t* bytes, size_t length, uint16_t* Charge_OUT_out, uint16_t* Charge_IN_out, uint8_t* SOC_out) {
    if (length < 5)
        return 0;

    *Charge_OUT_out = bytes[0] | bytes[1] << 8;
    *Charge_IN_out = bytes[2] | bytes[3] << 8;
    *SOC_out = bytes[4];
    return 1;
}

int ECUA_get_Estimation(ECUA_Estimation_t* data_out) {
    if (!(ECUA_Estimation_status.flags & CAN_MSG_RECEIVED))
        return 0;

#ifndef CANDB_IGNORE_TIMEOUTS
    if (txGetTimeMillis() > ECUA_Estimation_status.timestamp + ECUA_Estimation_timeout)
        return 0;
#endif

    if (data_out)
        memcpy(data_out, &ECUA_Estimation_data, sizeof(ECUA_Estimation_t));

    int flags = ECUA_Estimation_status.flags;
    ECUA_Estimation_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void ECUA_Estimation_on_receive(int (*callback)(ECUA_Estimation_t* data)) {
    ECUA_Estimation_status.on_receive = (void (*)(void)) callback;
}

int ECUA_decode_AMSOverall_s(const uint8_t* bytes, size_t length, ECUA_AMSOverall_t* data_out) {
    if (length < 8)
        return 0;

    data_out->Volt_Max = bytes[0] | bytes[1] << 8;
    data_out->Volt_Min = bytes[2] | bytes[3] << 8;
    data_out->Temp_Min = bytes[4];
    data_out->Temp_Max = bytes[5];
    data_out->Temp_Max_Index = bytes[6];
    data_out->Volt_Min_index = bytes[7];
    return 1;
}

int ECUA_decode_AMSOverall(const uint8_t* bytes, size_t length, uint16_t* Volt_Max_out, uint16_t* Volt_Min_out, int8_t* Temp_Min_out, int8_t* Temp_Max_out, uint8_t* Temp_Max_Index_out, uint8_t* Volt_Min_index_out) {
    if (length < 8)
        return 0;

    *Volt_Max_out = bytes[0] | bytes[1] << 8;
    *Volt_Min_out = bytes[2] | bytes[3] << 8;
    *Temp_Min_out = bytes[4];
    *Temp_Max_out = bytes[5];
    *Temp_Max_Index_out = bytes[6];
    *Volt_Min_index_out = bytes[7];
    return 1;
}

int ECUA_get_AMSOverall(ECUA_AMSOverall_t* data_out) {
    if (!(ECUA_AMSOverall_status.flags & CAN_MSG_RECEIVED))
        return 0;

    if (data_out)
        memcpy(data_out, &ECUA_AMSOverall_data, sizeof(ECUA_AMSOverall_t));

    int flags = ECUA_AMSOverall_status.flags;
    ECUA_AMSOverall_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void ECUA_AMSOverall_on_receive(int (*callback)(ECUA_AMSOverall_t* data)) {
    ECUA_AMSOverall_status.on_receive = (void (*)(void)) callback;
}

int ECUB_decode_Status_s(const uint8_t* bytes, size_t length, ECUB_Status_t* data_out) {
    if (length < 8)
        return 0;

    data_out->SDC_FRONT = (bytes[0] & 0x01);
    data_out->SDC_SDBL = ((bytes[0] >> 1) & 0x01);
    data_out->SDC_SDBR = ((bytes[0] >> 2) & 0x01);
    data_out->SDC_HVD = ((bytes[0] >> 3) & 0x01);
    data_out->SDC_BSPD = ((bytes[0] >> 4) & 0x01);
    data_out->SDC_MCUR = ((bytes[0] >> 5) & 0x01);
    data_out->SDC_AMS = ((bytes[0] >> 6) & 0x01);
    data_out->SDC_TSMS = ((bytes[0] >> 7) & 0x01);
    data_out->CarState = (enum ECUB_CarState) ((bytes[1] & 0x0F));
    data_out->CarState_Notready = (enum ECUB_Notready_reason) (((bytes[1] >> 4) & 0x0F));
    data_out->PowerSource = (enum ECUB_GLV_PowerSource) ((bytes[2] & 0x03));
    data_out->Det_MOD1 = ((bytes[2] >> 4) & 0x01);
    data_out->Det_MOD2 = ((bytes[2] >> 5) & 0x01);
    data_out->Det_MOD3 = ((bytes[2] >> 6) & 0x01);
    data_out->Det_MOD4 = ((bytes[2] >> 7) & 0x01);
    data_out->FT_PWR1_OT = (bytes[3] & 0x01);
    data_out->FT_PWR2_OT = ((bytes[3] >> 1) & 0x01);
    data_out->FT_PWR3_OT = ((bytes[3] >> 2) & 0x01);
    data_out->FT_PWR4_OT = ((bytes[3] >> 3) & 0x01);
    data_out->FT_PWR5_OT = ((bytes[3] >> 4) & 0x01);
    data_out->FT_L2_OT = ((bytes[3] >> 5) & 0x01);
    data_out->FT_ANY = ((bytes[3] >> 6) & 0x01);
    data_out->FT_L1_OT = ((bytes[3] >> 7) & 0x01);
    data_out->FT_PWR_ECUF_OC = (bytes[4] & 0x01);
    data_out->FT_PWR_ECUA_OC = ((bytes[4] >> 1) & 0x01);
    data_out->FT_PWR_MCF_OC = ((bytes[4] >> 2) & 0x01);
    data_out->FT_PWR_MCR_OC = ((bytes[4] >> 3) & 0x01);
    data_out->FT_CAN1 = ((bytes[4] >> 4) & 0x01);
    data_out->FT_CAN2 = ((bytes[4] >> 5) & 0x01);
    data_out->PWR_ECUF_EN = (bytes[5] & 0x01);
    data_out->PWR_ECUA_EN = ((bytes[5] >> 1) & 0x01);
    data_out->PWR_MCUF_EN = ((bytes[5] >> 2) & 0x01);
    data_out->PWR_MCUR_EN = ((bytes[5] >> 3) & 0x01);
    data_out->PWR_EM_EN = ((bytes[5] >> 4) & 0x01);
    data_out->PWR_WP1_EN = ((bytes[5] >> 5) & 0x01);
    data_out->PWR_WP2_EN = ((bytes[5] >> 6) & 0x01);
    data_out->PWR_FAN1_EN = ((bytes[5] >> 7) & 0x01);
    data_out->PWR_FAN2_EN = (bytes[6] & 0x01);
    data_out->PWR_FAN3_EN = ((bytes[6] >> 1) & 0x01);
    data_out->PWR_WS_EN = ((bytes[6] >> 2) & 0x01);
    data_out->PWR_AUX1_EN = ((bytes[6] >> 3) & 0x01);
    data_out->PWR_AUX2_EN = ((bytes[6] >> 4) & 0x01);
    data_out->PWR_AUX3_EN = ((bytes[6] >> 5) & 0x01);
    data_out->RTDS_EN = ((bytes[6] >> 6) & 0x01);
    data_out->SDBR_LED_EN = ((bytes[6] >> 7) & 0x01);
    data_out->SDBL_LED_EN = (bytes[7] & 0x01);
    data_out->BrakeLight_EN = ((bytes[7] >> 1) & 0x01);
    data_out->TSAL_Override = ((bytes[7] >> 2) & 0x01);
    data_out->SEQ = ((bytes[7] >> 4) & 0x0F);
    return 1;
}

int ECUB_decode_Status(const uint8_t* bytes, size_t length, uint8_t* SDC_FRONT_out, uint8_t* SDC_SDBL_out, uint8_t* SDC_SDBR_out, uint8_t* SDC_HVD_out, uint8_t* SDC_BSPD_out, uint8_t* SDC_MCUR_out, uint8_t* SDC_AMS_out, uint8_t* SDC_TSMS_out, enum ECUB_CarState* CarState_out, enum ECUB_Notready_reason* CarState_Notready_out, enum ECUB_GLV_PowerSource* PowerSource_out, uint8_t* Det_MOD1_out, uint8_t* Det_MOD2_out, uint8_t* Det_MOD3_out, uint8_t* Det_MOD4_out, uint8_t* FT_PWR1_OT_out, uint8_t* FT_PWR2_OT_out, uint8_t* FT_PWR3_OT_out, uint8_t* FT_PWR4_OT_out, uint8_t* FT_PWR5_OT_out, uint8_t* FT_L2_OT_out, uint8_t* FT_ANY_out, uint8_t* FT_L1_OT_out, uint8_t* FT_PWR_ECUF_OC_out, uint8_t* FT_PWR_ECUA_OC_out, uint8_t* FT_PWR_MCF_OC_out, uint8_t* FT_PWR_MCR_OC_out, uint8_t* FT_CAN1_out, uint8_t* FT_CAN2_out, uint8_t* PWR_ECUF_EN_out, uint8_t* PWR_ECUA_EN_out, uint8_t* PWR_MCUF_EN_out, uint8_t* PWR_MCUR_EN_out, uint8_t* PWR_EM_EN_out, uint8_t* PWR_WP1_EN_out, uint8_t* PWR_WP2_EN_out, uint8_t* PWR_FAN1_EN_out, uint8_t* PWR_FAN2_EN_out, uint8_t* PWR_FAN3_EN_out, uint8_t* PWR_WS_EN_out, uint8_t* PWR_AUX1_EN_out, uint8_t* PWR_AUX2_EN_out, uint8_t* PWR_AUX3_EN_out, uint8_t* RTDS_EN_out, uint8_t* SDBR_LED_EN_out, uint8_t* SDBL_LED_EN_out, uint8_t* BrakeLight_EN_out, uint8_t* TSAL_Override_out, uint8_t* SEQ_out) {
    if (length < 8)
        return 0;

    *SDC_FRONT_out = (bytes[0] & 0x01);
    *SDC_SDBL_out = ((bytes[0] >> 1) & 0x01);
    *SDC_SDBR_out = ((bytes[0] >> 2) & 0x01);
    *SDC_HVD_out = ((bytes[0] >> 3) & 0x01);
    *SDC_BSPD_out = ((bytes[0] >> 4) & 0x01);
    *SDC_MCUR_out = ((bytes[0] >> 5) & 0x01);
    *SDC_AMS_out = ((bytes[0] >> 6) & 0x01);
    *SDC_TSMS_out = ((bytes[0] >> 7) & 0x01);
    *CarState_out = (enum ECUB_CarState) ((bytes[1] & 0x0F));
    *CarState_Notready_out = (enum ECUB_Notready_reason) (((bytes[1] >> 4) & 0x0F));
    *PowerSource_out = (enum ECUB_GLV_PowerSource) ((bytes[2] & 0x03));
    *Det_MOD1_out = ((bytes[2] >> 4) & 0x01);
    *Det_MOD2_out = ((bytes[2] >> 5) & 0x01);
    *Det_MOD3_out = ((bytes[2] >> 6) & 0x01);
    *Det_MOD4_out = ((bytes[2] >> 7) & 0x01);
    *FT_PWR1_OT_out = (bytes[3] & 0x01);
    *FT_PWR2_OT_out = ((bytes[3] >> 1) & 0x01);
    *FT_PWR3_OT_out = ((bytes[3] >> 2) & 0x01);
    *FT_PWR4_OT_out = ((bytes[3] >> 3) & 0x01);
    *FT_PWR5_OT_out = ((bytes[3] >> 4) & 0x01);
    *FT_L2_OT_out = ((bytes[3] >> 5) & 0x01);
    *FT_ANY_out = ((bytes[3] >> 6) & 0x01);
    *FT_L1_OT_out = ((bytes[3] >> 7) & 0x01);
    *FT_PWR_ECUF_OC_out = (bytes[4] & 0x01);
    *FT_PWR_ECUA_OC_out = ((bytes[4] >> 1) & 0x01);
    *FT_PWR_MCF_OC_out = ((bytes[4] >> 2) & 0x01);
    *FT_PWR_MCR_OC_out = ((bytes[4] >> 3) & 0x01);
    *FT_CAN1_out = ((bytes[4] >> 4) & 0x01);
    *FT_CAN2_out = ((bytes[4] >> 5) & 0x01);
    *PWR_ECUF_EN_out = (bytes[5] & 0x01);
    *PWR_ECUA_EN_out = ((bytes[5] >> 1) & 0x01);
    *PWR_MCUF_EN_out = ((bytes[5] >> 2) & 0x01);
    *PWR_MCUR_EN_out = ((bytes[5] >> 3) & 0x01);
    *PWR_EM_EN_out = ((bytes[5] >> 4) & 0x01);
    *PWR_WP1_EN_out = ((bytes[5] >> 5) & 0x01);
    *PWR_WP2_EN_out = ((bytes[5] >> 6) & 0x01);
    *PWR_FAN1_EN_out = ((bytes[5] >> 7) & 0x01);
    *PWR_FAN2_EN_out = (bytes[6] & 0x01);
    *PWR_FAN3_EN_out = ((bytes[6] >> 1) & 0x01);
    *PWR_WS_EN_out = ((bytes[6] >> 2) & 0x01);
    *PWR_AUX1_EN_out = ((bytes[6] >> 3) & 0x01);
    *PWR_AUX2_EN_out = ((bytes[6] >> 4) & 0x01);
    *PWR_AUX3_EN_out = ((bytes[6] >> 5) & 0x01);
    *RTDS_EN_out = ((bytes[6] >> 6) & 0x01);
    *SDBR_LED_EN_out = ((bytes[6] >> 7) & 0x01);
    *SDBL_LED_EN_out = (bytes[7] & 0x01);
    *BrakeLight_EN_out = ((bytes[7] >> 1) & 0x01);
    *TSAL_Override_out = ((bytes[7] >> 2) & 0x01);
    *SEQ_out = ((bytes[7] >> 4) & 0x0F);
    return 1;
}

int ECUB_get_Status(ECUB_Status_t* data_out) {
    if (!(ECUB_Status_status.flags & CAN_MSG_RECEIVED))
        return 0;

#ifndef CANDB_IGNORE_TIMEOUTS
    if (txGetTimeMillis() > ECUB_Status_status.timestamp + ECUB_Status_timeout)
        return 0;
#endif

    if (data_out)
        memcpy(data_out, &ECUB_Status_data, sizeof(ECUB_Status_t));

    int flags = ECUB_Status_status.flags;
    ECUB_Status_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void ECUB_Status_on_receive(int (*callback)(ECUB_Status_t* data)) {
    ECUB_Status_status.on_receive = (void (*)(void)) callback;
}

int ECUB_decode_Cooling_s(const uint8_t* bytes, size_t length, ECUB_Cooling_t* data_out) {
    if (length < 7)
        return 0;

    data_out->WP1 = (bytes[0] & 0x0F);
    data_out->WP2 = ((bytes[0] >> 4) & 0x0F);
    data_out->FAN1 = (bytes[1] & 0x0F);
    data_out->FAN2 = ((bytes[1] >> 4) & 0x0F);
    data_out->FAN3 = (bytes[2] & 0x0F);
    data_out->WARN_MOT_FR_TEMP = (bytes[3] & 0x01);
    data_out->WARN_MOT_FL_TEMP = ((bytes[3] >> 1) & 0x01);
    data_out->WARN_MOT_RR_TEMP = ((bytes[3] >> 2) & 0x01);
    data_out->WARN_MOT_RL_TEMP = ((bytes[3] >> 3) & 0x01);
    data_out->WARN_MCU_FR_TEMP = ((bytes[3] >> 4) & 0x01);
    data_out->WARN_MCU_FL_TEMP = ((bytes[3] >> 5) & 0x01);
    data_out->WARN_MCU_RR_TEMP = ((bytes[3] >> 6) & 0x01);
    data_out->WARN_MCU_RL_TEMP = ((bytes[3] >> 7) & 0x01);
    data_out->WARN_Brake_RR_TEMP = (bytes[4] & 0x01);
    data_out->WARN_Brake_RL_TEMP = ((bytes[4] >> 1) & 0x01);
    data_out->FT_MOT_FR_OT = (bytes[5] & 0x01);
    data_out->FT_MOT_FL_OT = ((bytes[5] >> 1) & 0x01);
    data_out->FT_MOT_RR_OT = ((bytes[5] >> 2) & 0x01);
    data_out->FT_MOT_RL_OT = ((bytes[5] >> 3) & 0x01);
    data_out->FT_MCU_FR_OT = ((bytes[5] >> 4) & 0x01);
    data_out->FT_MCU_FL_OT = ((bytes[5] >> 5) & 0x01);
    data_out->FT_MCU_RR_OT = ((bytes[5] >> 6) & 0x01);
    data_out->FT_MCU_RL_OT = ((bytes[5] >> 7) & 0x01);
    data_out->FT_Brake_RR_OT = (bytes[6] & 0x01);
    data_out->FT_Brake_RL_OT = ((bytes[6] >> 1) & 0x01);
    return 1;
}

int ECUB_decode_Cooling(const uint8_t* bytes, size_t length, uint8_t* WP1_out, uint8_t* WP2_out, uint8_t* FAN1_out, uint8_t* FAN2_out, uint8_t* FAN3_out, uint8_t* WARN_MOT_FR_TEMP_out, uint8_t* WARN_MOT_FL_TEMP_out, uint8_t* WARN_MOT_RR_TEMP_out, uint8_t* WARN_MOT_RL_TEMP_out, uint8_t* WARN_MCU_FR_TEMP_out, uint8_t* WARN_MCU_FL_TEMP_out, uint8_t* WARN_MCU_RR_TEMP_out, uint8_t* WARN_MCU_RL_TEMP_out, uint8_t* WARN_Brake_RR_TEMP_out, uint8_t* WARN_Brake_RL_TEMP_out, uint8_t* FT_MOT_FR_OT_out, uint8_t* FT_MOT_FL_OT_out, uint8_t* FT_MOT_RR_OT_out, uint8_t* FT_MOT_RL_OT_out, uint8_t* FT_MCU_FR_OT_out, uint8_t* FT_MCU_FL_OT_out, uint8_t* FT_MCU_RR_OT_out, uint8_t* FT_MCU_RL_OT_out, uint8_t* FT_Brake_RR_OT_out, uint8_t* FT_Brake_RL_OT_out) {
    if (length < 7)
        return 0;

    *WP1_out = (bytes[0] & 0x0F);
    *WP2_out = ((bytes[0] >> 4) & 0x0F);
    *FAN1_out = (bytes[1] & 0x0F);
    *FAN2_out = ((bytes[1] >> 4) & 0x0F);
    *FAN3_out = (bytes[2] & 0x0F);
    *WARN_MOT_FR_TEMP_out = (bytes[3] & 0x01);
    *WARN_MOT_FL_TEMP_out = ((bytes[3] >> 1) & 0x01);
    *WARN_MOT_RR_TEMP_out = ((bytes[3] >> 2) & 0x01);
    *WARN_MOT_RL_TEMP_out = ((bytes[3] >> 3) & 0x01);
    *WARN_MCU_FR_TEMP_out = ((bytes[3] >> 4) & 0x01);
    *WARN_MCU_FL_TEMP_out = ((bytes[3] >> 5) & 0x01);
    *WARN_MCU_RR_TEMP_out = ((bytes[3] >> 6) & 0x01);
    *WARN_MCU_RL_TEMP_out = ((bytes[3] >> 7) & 0x01);
    *WARN_Brake_RR_TEMP_out = (bytes[4] & 0x01);
    *WARN_Brake_RL_TEMP_out = ((bytes[4] >> 1) & 0x01);
    *FT_MOT_FR_OT_out = (bytes[5] & 0x01);
    *FT_MOT_FL_OT_out = ((bytes[5] >> 1) & 0x01);
    *FT_MOT_RR_OT_out = ((bytes[5] >> 2) & 0x01);
    *FT_MOT_RL_OT_out = ((bytes[5] >> 3) & 0x01);
    *FT_MCU_FR_OT_out = ((bytes[5] >> 4) & 0x01);
    *FT_MCU_FL_OT_out = ((bytes[5] >> 5) & 0x01);
    *FT_MCU_RR_OT_out = ((bytes[5] >> 6) & 0x01);
    *FT_MCU_RL_OT_out = ((bytes[5] >> 7) & 0x01);
    *FT_Brake_RR_OT_out = (bytes[6] & 0x01);
    *FT_Brake_RL_OT_out = ((bytes[6] >> 1) & 0x01);
    return 1;
}

int ECUB_get_Cooling(ECUB_Cooling_t* data_out) {
    if (!(ECUB_Cooling_status.flags & CAN_MSG_RECEIVED))
        return 0;

    if (data_out)
        memcpy(data_out, &ECUB_Cooling_data, sizeof(ECUB_Cooling_t));

    int flags = ECUB_Cooling_status.flags;
    ECUB_Cooling_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void ECUB_Cooling_on_receive(int (*callback)(ECUB_Cooling_t* data)) {
    ECUB_Cooling_status.on_receive = (void (*)(void)) callback;
}

int ECUB_decode_TEMPSuspR_s(const uint8_t* bytes, size_t length, ECUB_TEMPSuspR_t* data_out) {
    if (length < 8)
        return 0;

    data_out->BrakeCal_RR = bytes[0];
    data_out->BrakeCal_RL = bytes[1];
    data_out->TireI_RR = bytes[2];
    data_out->TireC_RR = bytes[3];
    data_out->TireO_RR = bytes[4];
    data_out->TireI_RL = bytes[5];
    data_out->TireC_RL = bytes[6];
    data_out->TireO_RL = bytes[7];
    return 1;
}

int ECUB_decode_TEMPSuspR(const uint8_t* bytes, size_t length, uint8_t* BrakeCal_RR_out, uint8_t* BrakeCal_RL_out, uint8_t* TireI_RR_out, uint8_t* TireC_RR_out, uint8_t* TireO_RR_out, uint8_t* TireI_RL_out, uint8_t* TireC_RL_out, uint8_t* TireO_RL_out) {
    if (length < 8)
        return 0;

    *BrakeCal_RR_out = bytes[0];
    *BrakeCal_RL_out = bytes[1];
    *TireI_RR_out = bytes[2];
    *TireC_RR_out = bytes[3];
    *TireO_RR_out = bytes[4];
    *TireI_RL_out = bytes[5];
    *TireC_RL_out = bytes[6];
    *TireO_RL_out = bytes[7];
    return 1;
}

int ECUB_get_TEMPSuspR(ECUB_TEMPSuspR_t* data_out) {
    if (!(ECUB_TEMPSuspR_status.flags & CAN_MSG_RECEIVED))
        return 0;

    if (data_out)
        memcpy(data_out, &ECUB_TEMPSuspR_data, sizeof(ECUB_TEMPSuspR_t));

    int flags = ECUB_TEMPSuspR_status.flags;
    ECUB_TEMPSuspR_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void ECUB_TEMPSuspR_on_receive(int (*callback)(ECUB_TEMPSuspR_t* data)) {
    ECUB_TEMPSuspR_status.on_receive = (void (*)(void)) callback;
}

int ECUB_decode_TEMPAux_s(const uint8_t* bytes, size_t length, ECUB_TEMPAux_t* data_out) {
    if (length < 4)
        return 0;

    data_out->Cooling1_NTC = bytes[0];
    data_out->Cooling2_NTC = bytes[1];
    data_out->Cooling3_NTC = bytes[2];
    data_out->Cooling4_NTC = bytes[3];
    return 1;
}

int ECUB_decode_TEMPAux(const uint8_t* bytes, size_t length, uint8_t* Cooling1_NTC_out, uint8_t* Cooling2_NTC_out, uint8_t* Cooling3_NTC_out, uint8_t* Cooling4_NTC_out) {
    if (length < 4)
        return 0;

    *Cooling1_NTC_out = bytes[0];
    *Cooling2_NTC_out = bytes[1];
    *Cooling3_NTC_out = bytes[2];
    *Cooling4_NTC_out = bytes[3];
    return 1;
}

int ECUB_get_TEMPAux(ECUB_TEMPAux_t* data_out) {
    if (!(ECUB_TEMPAux_status.flags & CAN_MSG_RECEIVED))
        return 0;

    if (data_out)
        memcpy(data_out, &ECUB_TEMPAux_data, sizeof(ECUB_TEMPAux_t));

    int flags = ECUB_TEMPAux_status.flags;
    ECUB_TEMPAux_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void ECUB_TEMPAux_on_receive(int (*callback)(ECUB_TEMPAux_t* data)) {
    ECUB_TEMPAux_status.on_receive = (void (*)(void)) callback;
}

int ECUF_decode_Status_s(const uint8_t* bytes, size_t length, ECUF_Status_t* data_out) {
    if (length < 6)
        return 0;

    data_out->SDC_SDBC = (bytes[0] & 0x01);
    data_out->SDC_Inertia = ((bytes[0] >> 1) & 0x01);
    data_out->SDC_FWIL = ((bytes[0] >> 2) & 0x01);
    data_out->PWR_ECUP_EN = (bytes[1] & 0x01);
    data_out->PWR_ECUG_EN = ((bytes[1] >> 1) & 0x01);
    data_out->PWR_DTLG_EN = ((bytes[1] >> 2) & 0x01);
    data_out->PWR_ECUS_EN = ((bytes[1] >> 3) & 0x01);
    data_out->PWR_DASH_EN = ((bytes[1] >> 4) & 0x01);
    data_out->PWR_FAN_BrakeF_EN = ((bytes[1] >> 5) & 0x01);
    data_out->WARN_Brake_FR_TEMP = ((bytes[1] >> 6) & 0x01);
    data_out->WARN_Brake_FL_TEMP = ((bytes[1] >> 7) & 0x01);
    data_out->FT_PWR_ECUP = (bytes[2] & 0x01);
    data_out->FT_PWR_ECUG = ((bytes[2] >> 1) & 0x01);
    data_out->FT_PWR_ECUS = ((bytes[2] >> 2) & 0x01);
    data_out->FT_PWR_DTLG = ((bytes[2] >> 3) & 0x01);
    data_out->FT_PWR_DASH = ((bytes[2] >> 4) & 0x01);
    data_out->FT_PWR_FAN_BrakeF = ((bytes[2] >> 5) & 0x01);
    data_out->FT_STW_Sensor = ((bytes[2] >> 6) & 0x01);
    data_out->FT_STW_Cal = ((bytes[2] >> 7) & 0x01);
    data_out->FT_DisFR = (bytes[3] & 0x01);
    data_out->FT_DisFL = ((bytes[3] >> 1) & 0x01);
    data_out->FT_DisRR = ((bytes[3] >> 2) & 0x01);
    data_out->FT_DisRL = ((bytes[3] >> 3) & 0x01);
    data_out->FT_DisFR_Cal = ((bytes[3] >> 4) & 0x01);
    data_out->FT_DisFL_Cal = ((bytes[3] >> 5) & 0x01);
    data_out->FT_DisRR_Cal = ((bytes[3] >> 6) & 0x01);
    data_out->FT_DisRL_Cal = ((bytes[3] >> 7) & 0x01);
    data_out->FT_Brake_FR_OT = (bytes[4] & 0x01);
    data_out->FT_Brake_FL_OT = ((bytes[4] >> 1) & 0x01);
    data_out->Volt_GLV_In = bytes[5];
    return 1;
}

int ECUF_decode_Status(const uint8_t* bytes, size_t length, uint8_t* SDC_SDBC_out, uint8_t* SDC_Inertia_out, uint8_t* SDC_FWIL_out, uint8_t* PWR_ECUP_EN_out, uint8_t* PWR_ECUG_EN_out, uint8_t* PWR_DTLG_EN_out, uint8_t* PWR_ECUS_EN_out, uint8_t* PWR_DASH_EN_out, uint8_t* PWR_FAN_BrakeF_EN_out, uint8_t* WARN_Brake_FR_TEMP_out, uint8_t* WARN_Brake_FL_TEMP_out, uint8_t* FT_PWR_ECUP_out, uint8_t* FT_PWR_ECUG_out, uint8_t* FT_PWR_ECUS_out, uint8_t* FT_PWR_DTLG_out, uint8_t* FT_PWR_DASH_out, uint8_t* FT_PWR_FAN_BrakeF_out, uint8_t* FT_STW_Sensor_out, uint8_t* FT_STW_Cal_out, uint8_t* FT_DisFR_out, uint8_t* FT_DisFL_out, uint8_t* FT_DisRR_out, uint8_t* FT_DisRL_out, uint8_t* FT_DisFR_Cal_out, uint8_t* FT_DisFL_Cal_out, uint8_t* FT_DisRR_Cal_out, uint8_t* FT_DisRL_Cal_out, uint8_t* FT_Brake_FR_OT_out, uint8_t* FT_Brake_FL_OT_out, uint8_t* Volt_GLV_In_out) {
    if (length < 6)
        return 0;

    *SDC_SDBC_out = (bytes[0] & 0x01);
    *SDC_Inertia_out = ((bytes[0] >> 1) & 0x01);
    *SDC_FWIL_out = ((bytes[0] >> 2) & 0x01);
    *PWR_ECUP_EN_out = (bytes[1] & 0x01);
    *PWR_ECUG_EN_out = ((bytes[1] >> 1) & 0x01);
    *PWR_DTLG_EN_out = ((bytes[1] >> 2) & 0x01);
    *PWR_ECUS_EN_out = ((bytes[1] >> 3) & 0x01);
    *PWR_DASH_EN_out = ((bytes[1] >> 4) & 0x01);
    *PWR_FAN_BrakeF_EN_out = ((bytes[1] >> 5) & 0x01);
    *WARN_Brake_FR_TEMP_out = ((bytes[1] >> 6) & 0x01);
    *WARN_Brake_FL_TEMP_out = ((bytes[1] >> 7) & 0x01);
    *FT_PWR_ECUP_out = (bytes[2] & 0x01);
    *FT_PWR_ECUG_out = ((bytes[2] >> 1) & 0x01);
    *FT_PWR_ECUS_out = ((bytes[2] >> 2) & 0x01);
    *FT_PWR_DTLG_out = ((bytes[2] >> 3) & 0x01);
    *FT_PWR_DASH_out = ((bytes[2] >> 4) & 0x01);
    *FT_PWR_FAN_BrakeF_out = ((bytes[2] >> 5) & 0x01);
    *FT_STW_Sensor_out = ((bytes[2] >> 6) & 0x01);
    *FT_STW_Cal_out = ((bytes[2] >> 7) & 0x01);
    *FT_DisFR_out = (bytes[3] & 0x01);
    *FT_DisFL_out = ((bytes[3] >> 1) & 0x01);
    *FT_DisRR_out = ((bytes[3] >> 2) & 0x01);
    *FT_DisRL_out = ((bytes[3] >> 3) & 0x01);
    *FT_DisFR_Cal_out = ((bytes[3] >> 4) & 0x01);
    *FT_DisFL_Cal_out = ((bytes[3] >> 5) & 0x01);
    *FT_DisRR_Cal_out = ((bytes[3] >> 6) & 0x01);
    *FT_DisRL_Cal_out = ((bytes[3] >> 7) & 0x01);
    *FT_Brake_FR_OT_out = (bytes[4] & 0x01);
    *FT_Brake_FL_OT_out = ((bytes[4] >> 1) & 0x01);
    *Volt_GLV_In_out = bytes[5];
    return 1;
}

int ECUF_get_Status(ECUF_Status_t* data_out) {
    if (!(ECUF_Status_status.flags & CAN_MSG_RECEIVED))
        return 0;

#ifndef CANDB_IGNORE_TIMEOUTS
    if (txGetTimeMillis() > ECUF_Status_status.timestamp + ECUF_Status_timeout)
        return 0;
#endif

    if (data_out)
        memcpy(data_out, &ECUF_Status_data, sizeof(ECUF_Status_t));

    int flags = ECUF_Status_status.flags;
    ECUF_Status_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void ECUF_Status_on_receive(int (*callback)(ECUF_Status_t* data)) {
    ECUF_Status_status.on_receive = (void (*)(void)) callback;
}

int ECUF_decode_STW_s(const uint8_t* bytes, size_t length, ECUF_STW_t* data_out) {
    if (length < 6)
        return 0;

    data_out->Angle = bytes[0] | bytes[1] << 8;
    data_out->AngularSpeed = bytes[2] | bytes[3] << 8;
    data_out->FT_STW = (bytes[4] & 0x01);
    data_out->SEQ = ((bytes[5] >> 4) & 0x0F);
    return 1;
}

int ECUF_decode_STW(const uint8_t* bytes, size_t length, int16_t* Angle_out, int16_t* AngularSpeed_out, uint8_t* FT_STW_out, uint8_t* SEQ_out) {
    if (length < 6)
        return 0;

    *Angle_out = bytes[0] | bytes[1] << 8;
    *AngularSpeed_out = bytes[2] | bytes[3] << 8;
    *FT_STW_out = (bytes[4] & 0x01);
    *SEQ_out = ((bytes[5] >> 4) & 0x0F);
    return 1;
}

int ECUF_get_STW(ECUF_STW_t* data_out) {
    if (!(ECUF_STW_status.flags & CAN_MSG_RECEIVED))
        return 0;

#ifndef CANDB_IGNORE_TIMEOUTS
    if (txGetTimeMillis() > ECUF_STW_status.timestamp + ECUF_STW_timeout)
        return 0;
#endif

    if (data_out)
        memcpy(data_out, &ECUF_STW_data, sizeof(ECUF_STW_t));

    int flags = ECUF_STW_status.flags;
    ECUF_STW_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void ECUF_STW_on_receive(int (*callback)(ECUF_STW_t* data)) {
    ECUF_STW_status.on_receive = (void (*)(void)) callback;
}

int ECUF_decode_TEMPSuspF_s(const uint8_t* bytes, size_t length, ECUF_TEMPSuspF_t* data_out) {
    if (length < 8)
        return 0;

    data_out->BrakeCal_FR = bytes[0];
    data_out->BrakeCal_FL = bytes[1];
    data_out->TireI_FR = bytes[2];
    data_out->TireC_FR = bytes[3];
    data_out->TireO_FR = bytes[4];
    data_out->TireI_FL = bytes[5];
    data_out->TireC_FL = bytes[6];
    data_out->TireO_FL = bytes[7];
    return 1;
}

int ECUF_decode_TEMPSuspF(const uint8_t* bytes, size_t length, uint8_t* BrakeCal_FR_out, uint8_t* BrakeCal_FL_out, uint8_t* TireI_FR_out, uint8_t* TireC_FR_out, uint8_t* TireO_FR_out, uint8_t* TireI_FL_out, uint8_t* TireC_FL_out, uint8_t* TireO_FL_out) {
    if (length < 8)
        return 0;

    *BrakeCal_FR_out = bytes[0];
    *BrakeCal_FL_out = bytes[1];
    *TireI_FR_out = bytes[2];
    *TireC_FR_out = bytes[3];
    *TireO_FR_out = bytes[4];
    *TireI_FL_out = bytes[5];
    *TireC_FL_out = bytes[6];
    *TireO_FL_out = bytes[7];
    return 1;
}

int ECUF_get_TEMPSuspF(ECUF_TEMPSuspF_t* data_out) {
    if (!(ECUF_TEMPSuspF_status.flags & CAN_MSG_RECEIVED))
        return 0;

    if (data_out)
        memcpy(data_out, &ECUF_TEMPSuspF_data, sizeof(ECUF_TEMPSuspF_t));

    int flags = ECUF_TEMPSuspF_status.flags;
    ECUF_TEMPSuspF_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void ECUF_TEMPSuspF_on_receive(int (*callback)(ECUF_TEMPSuspF_t* data)) {
    ECUF_TEMPSuspF_status.on_receive = (void (*)(void)) callback;
}

int ECUF_send_REQCalibSTW_s(const ECUF_REQCalibSTW_t* data) {
    uint8_t buffer[1];
    buffer[0] = (data->which & 0x0F);
    int rc = txSendCANMessage(ECUF_REQCalibSTW_id, buffer, sizeof(buffer));
    return rc;
}

int ECUF_send_REQCalibSTW(enum ECUF_CAL_STWIndex which) {
    uint8_t buffer[1];
    buffer[0] = (which & 0x0F);
    int rc = txSendCANMessage(ECUF_REQCalibSTW_id, buffer, sizeof(buffer));
    return rc;
}

int ECUP_decode_Status_s(const uint8_t* bytes, size_t length, ECUP_Status_t* data_out) {
    if (length < 2)
        return 0;

    data_out->SDC_BOTS = (bytes[0] & 0x01);
    data_out->FT_ANY = (bytes[1] & 0x01);
    data_out->APPS_Plausible = ((bytes[1] >> 1) & 0x01);
    data_out->BPPC_Latch = ((bytes[1] >> 2) & 0x01);
    data_out->BrakeActive = ((bytes[1] >> 3) & 0x01);
    data_out->BrakeActive_BSPD = ((bytes[1] >> 4) & 0x01);
    return 1;
}

int ECUP_decode_Status(const uint8_t* bytes, size_t length, uint8_t* SDC_BOTS_out, uint8_t* FT_ANY_out, uint8_t* APPS_Plausible_out, uint8_t* BPPC_Latch_out, uint8_t* BrakeActive_out, uint8_t* BrakeActive_BSPD_out) {
    if (length < 2)
        return 0;

    *SDC_BOTS_out = (bytes[0] & 0x01);
    *FT_ANY_out = (bytes[1] & 0x01);
    *APPS_Plausible_out = ((bytes[1] >> 1) & 0x01);
    *BPPC_Latch_out = ((bytes[1] >> 2) & 0x01);
    *BrakeActive_out = ((bytes[1] >> 3) & 0x01);
    *BrakeActive_BSPD_out = ((bytes[1] >> 4) & 0x01);
    return 1;
}

int ECUP_get_Status(ECUP_Status_t* data_out) {
    if (!(ECUP_Status_status.flags & CAN_MSG_RECEIVED))
        return 0;

#ifndef CANDB_IGNORE_TIMEOUTS
    if (txGetTimeMillis() > ECUP_Status_status.timestamp + ECUP_Status_timeout)
        return 0;
#endif

    if (data_out)
        memcpy(data_out, &ECUP_Status_data, sizeof(ECUP_Status_t));

    int flags = ECUP_Status_status.flags;
    ECUP_Status_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void ECUP_Status_on_receive(int (*callback)(ECUP_Status_t* data)) {
    ECUP_Status_status.on_receive = (void (*)(void)) callback;
}

int ECUP_decode_Pedals_s(const uint8_t* bytes, size_t length, ECUP_Pedals_t* data_out) {
    if (length < 6)
        return 0;

    data_out->APPS_pos = bytes[0] | bytes[1] << 8;
    data_out->Brake_pos = bytes[2] | bytes[3] << 8;
    data_out->FT_APPS_pos = (bytes[4] & 0x01);
    data_out->FT_Brake_Pos = ((bytes[4] >> 1) & 0x01);
    data_out->SEQ = ((bytes[5] >> 4) & 0x0F);
    return 1;
}

int ECUP_decode_Pedals(const uint8_t* bytes, size_t length, uint16_t* APPS_pos_out, uint16_t* Brake_pos_out, uint8_t* FT_APPS_pos_out, uint8_t* FT_Brake_Pos_out, uint8_t* SEQ_out) {
    if (length < 6)
        return 0;

    *APPS_pos_out = bytes[0] | bytes[1] << 8;
    *Brake_pos_out = bytes[2] | bytes[3] << 8;
    *FT_APPS_pos_out = (bytes[4] & 0x01);
    *FT_Brake_Pos_out = ((bytes[4] >> 1) & 0x01);
    *SEQ_out = ((bytes[5] >> 4) & 0x0F);
    return 1;
}

int ECUP_get_Pedals(ECUP_Pedals_t* data_out) {
    if (!(ECUP_Pedals_status.flags & CAN_MSG_RECEIVED))
        return 0;

#ifndef CANDB_IGNORE_TIMEOUTS
    if (txGetTimeMillis() > ECUP_Pedals_status.timestamp + ECUP_Pedals_timeout)
        return 0;
#endif

    if (data_out)
        memcpy(data_out, &ECUP_Pedals_data, sizeof(ECUP_Pedals_t));

    int flags = ECUP_Pedals_status.flags;
    ECUP_Pedals_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void ECUP_Pedals_on_receive(int (*callback)(ECUP_Pedals_t* data)) {
    ECUP_Pedals_status.on_receive = (void (*)(void)) callback;
}

int ECUP_decode_Pressure_s(const uint8_t* bytes, size_t length, ECUP_Pressure_t* data_out) {
    if (length < 5)
        return 0;

    data_out->BrakeF = bytes[0] | bytes[1] << 8;
    data_out->BrakeR = bytes[2] | bytes[3] << 8;
    data_out->FT_BrakeF = (bytes[4] & 0x01);
    data_out->FT_BrakeR = ((bytes[4] >> 1) & 0x01);
    return 1;
}

int ECUP_decode_Pressure(const uint8_t* bytes, size_t length, uint16_t* BrakeF_out, uint16_t* BrakeR_out, uint8_t* FT_BrakeF_out, uint8_t* FT_BrakeR_out) {
    if (length < 5)
        return 0;

    *BrakeF_out = bytes[0] | bytes[1] << 8;
    *BrakeR_out = bytes[2] | bytes[3] << 8;
    *FT_BrakeF_out = (bytes[4] & 0x01);
    *FT_BrakeR_out = ((bytes[4] >> 1) & 0x01);
    return 1;
}

int ECUP_get_Pressure(ECUP_Pressure_t* data_out) {
    if (!(ECUP_Pressure_status.flags & CAN_MSG_RECEIVED))
        return 0;

    if (data_out)
        memcpy(data_out, &ECUP_Pressure_data, sizeof(ECUP_Pressure_t));

    int flags = ECUP_Pressure_status.flags;
    ECUP_Pressure_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void ECUP_Pressure_on_receive(int (*callback)(ECUP_Pressure_t* data)) {
    ECUP_Pressure_status.on_receive = (void (*)(void)) callback;
}

int ECUP_send_REQCalibPedal_s(const ECUP_REQCalibPedal_t* data) {
    uint8_t buffer[1];
    buffer[0] = (data->which & 0x0F);
    int rc = txSendCANMessage(ECUP_REQCalibPedal_id, buffer, sizeof(buffer));
    return rc;
}

int ECUP_send_REQCalibPedal(enum ECUP_CAL_PedalIndex which) {
    uint8_t buffer[1];
    buffer[0] = (which & 0x0F);
    int rc = txSendCANMessage(ECUP_REQCalibPedal_id, buffer, sizeof(buffer));
    return rc;
}

int ECUP_decode_DiagPos_s(const uint8_t* bytes, size_t length, ECUP_DiagPos_t* data_out) {
    if (length < 8)
        return 0;

    data_out->Acc1_raw = bytes[0] | bytes[1] << 8;
    data_out->Acc2_raw = bytes[2] | bytes[3] << 8;
    data_out->BrkPos_raw = bytes[4] | bytes[5] << 8;
    data_out->BPPC_raw = bytes[6] | bytes[7] << 8;
    return 1;
}

int ECUP_decode_DiagPos(const uint8_t* bytes, size_t length, uint16_t* Acc1_raw_out, uint16_t* Acc2_raw_out, uint16_t* BrkPos_raw_out, uint16_t* BPPC_raw_out) {
    if (length < 8)
        return 0;

    *Acc1_raw_out = bytes[0] | bytes[1] << 8;
    *Acc2_raw_out = bytes[2] | bytes[3] << 8;
    *BrkPos_raw_out = bytes[4] | bytes[5] << 8;
    *BPPC_raw_out = bytes[6] | bytes[7] << 8;
    return 1;
}

int ECUP_get_DiagPos(ECUP_DiagPos_t* data_out) {
    if (!(ECUP_DiagPos_status.flags & CAN_MSG_RECEIVED))
        return 0;

#ifndef CANDB_IGNORE_TIMEOUTS
    if (txGetTimeMillis() > ECUP_DiagPos_status.timestamp + ECUP_DiagPos_timeout)
        return 0;
#endif

    if (data_out)
        memcpy(data_out, &ECUP_DiagPos_data, sizeof(ECUP_DiagPos_t));

    int flags = ECUP_DiagPos_status.flags;
    ECUP_DiagPos_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void ECUP_DiagPos_on_receive(int (*callback)(ECUP_DiagPos_t* data)) {
    ECUP_DiagPos_status.on_receive = (void (*)(void)) callback;
}

int ECUS_send_Status_s(const ECUS_Status_t* data) {
    uint8_t buffer[1];
    buffer[0] = (data->SEQ & 0x0F);
    int rc = txSendCANMessage(ECUS_Status_id, buffer, sizeof(buffer));

    if (rc == 0) {
        ECUS_Status_last_sent = txGetTimeMillis();
    }

    return rc;
}

int ECUS_send_Status(uint8_t SEQ) {
    uint8_t buffer[1];
    buffer[0] = (SEQ & 0x0F);
    int rc = txSendCANMessage(ECUS_Status_id, buffer, sizeof(buffer));

    if (rc == 0) {
        ECUS_Status_last_sent = txGetTimeMillis();
    }

    return rc;
}

int ECUS_Status_need_to_send(void) {
    return (ECUS_Status_last_sent == -1) || (txGetTimeMillis() >= ECUS_Status_last_sent + 100);
}

int IMU_decode_Status_s(const uint8_t* bytes, size_t length, IMU_Status_t* data_out) {
    if (length < 3)
        return 0;

    data_out->State = (bytes[1] & 0x0F);
    data_out->FT_ACC_Cal = (bytes[2] & 0x01);
    data_out->FT_Gyro_Cal = ((bytes[2] >> 1) & 0x01);
    data_out->FT_Mount_Cal = ((bytes[2] >> 2) & 0x01);
    return 1;
}

int IMU_decode_Status(const uint8_t* bytes, size_t length, uint8_t* State_out, uint8_t* FT_ACC_Cal_out, uint8_t* FT_Gyro_Cal_out, uint8_t* FT_Mount_Cal_out) {
    if (length < 3)
        return 0;

    *State_out = (bytes[1] & 0x0F);
    *FT_ACC_Cal_out = (bytes[2] & 0x01);
    *FT_Gyro_Cal_out = ((bytes[2] >> 1) & 0x01);
    *FT_Mount_Cal_out = ((bytes[2] >> 2) & 0x01);
    return 1;
}

int IMU_get_Status(IMU_Status_t* data_out) {
    if (!(IMU_Status_status.flags & CAN_MSG_RECEIVED))
        return 0;

#ifndef CANDB_IGNORE_TIMEOUTS
    if (txGetTimeMillis() > IMU_Status_status.timestamp + IMU_Status_timeout)
        return 0;
#endif

    if (data_out)
        memcpy(data_out, &IMU_Status_data, sizeof(IMU_Status_t));

    int flags = IMU_Status_status.flags;
    IMU_Status_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void IMU_Status_on_receive(int (*callback)(IMU_Status_t* data)) {
    IMU_Status_status.on_receive = (void (*)(void)) callback;
}

int MCR_decode_GeneralReport_s(const uint8_t* bytes, size_t length, MCR_GeneralReport_t* data_out) {
    if (length < 8)
        return 0;

    data_out->SDC_IN = (bytes[0] & 0x01);
    data_out->SDC_MSCB = ((bytes[0] >> 1) & 0x01);
    data_out->SDC_MPCB = ((bytes[0] >> 2) & 0x01);
    data_out->SDC_HVC = ((bytes[0] >> 3) & 0x01);
    data_out->SDC_MPCA = ((bytes[0] >> 4) & 0x01);
    data_out->SDC_MSCA = ((bytes[0] >> 5) & 0x01);
    data_out->DISCH = (bytes[1] & 0x01);
    data_out->POA = ((bytes[1] >> 1) & 0x01);
    data_out->POA_PS = ((bytes[1] >> 2) & 0x01);
    data_out->POB = ((bytes[1] >> 3) & 0x01);
    data_out->POB_PS = ((bytes[1] >> 4) & 0x01);
    data_out->PWMA = (bytes[2] & 0x01);
    data_out->FWA = ((bytes[2] >> 1) & 0x01);
    data_out->GENA = ((bytes[2] >> 2) & 0x01);
    data_out->DIRA = ((bytes[2] >> 3) & 0x01);
    data_out->PWMB = ((bytes[2] >> 4) & 0x01);
    data_out->FWB = ((bytes[2] >> 5) & 0x01);
    data_out->GENB = ((bytes[2] >> 6) & 0x01);
    data_out->DIRB = ((bytes[2] >> 7) & 0x01);
    data_out->HB = bytes[7];
    return 1;
}

int MCR_decode_GeneralReport(const uint8_t* bytes, size_t length, uint8_t* SDC_IN_out, uint8_t* SDC_MSCB_out, uint8_t* SDC_MPCB_out, uint8_t* SDC_HVC_out, uint8_t* SDC_MPCA_out, uint8_t* SDC_MSCA_out, uint8_t* DISCH_out, uint8_t* POA_out, uint8_t* POA_PS_out, uint8_t* POB_out, uint8_t* POB_PS_out, uint8_t* PWMA_out, uint8_t* FWA_out, uint8_t* GENA_out, uint8_t* DIRA_out, uint8_t* PWMB_out, uint8_t* FWB_out, uint8_t* GENB_out, uint8_t* DIRB_out, uint8_t* HB_out) {
    if (length < 8)
        return 0;

    *SDC_IN_out = (bytes[0] & 0x01);
    *SDC_MSCB_out = ((bytes[0] >> 1) & 0x01);
    *SDC_MPCB_out = ((bytes[0] >> 2) & 0x01);
    *SDC_HVC_out = ((bytes[0] >> 3) & 0x01);
    *SDC_MPCA_out = ((bytes[0] >> 4) & 0x01);
    *SDC_MSCA_out = ((bytes[0] >> 5) & 0x01);
    *DISCH_out = (bytes[1] & 0x01);
    *POA_out = ((bytes[1] >> 1) & 0x01);
    *POA_PS_out = ((bytes[1] >> 2) & 0x01);
    *POB_out = ((bytes[1] >> 3) & 0x01);
    *POB_PS_out = ((bytes[1] >> 4) & 0x01);
    *PWMA_out = (bytes[2] & 0x01);
    *FWA_out = ((bytes[2] >> 1) & 0x01);
    *GENA_out = ((bytes[2] >> 2) & 0x01);
    *DIRA_out = ((bytes[2] >> 3) & 0x01);
    *PWMB_out = ((bytes[2] >> 4) & 0x01);
    *FWB_out = ((bytes[2] >> 5) & 0x01);
    *GENB_out = ((bytes[2] >> 6) & 0x01);
    *DIRB_out = ((bytes[2] >> 7) & 0x01);
    *HB_out = bytes[7];
    return 1;
}

int MCR_get_GeneralReport(MCR_GeneralReport_t* data_out) {
    if (!(MCR_GeneralReport_status.flags & CAN_MSG_RECEIVED))
        return 0;

    if (data_out)
        memcpy(data_out, &MCR_GeneralReport_data, sizeof(MCR_GeneralReport_t));

    int flags = MCR_GeneralReport_status.flags;
    MCR_GeneralReport_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void MCR_GeneralReport_on_receive(int (*callback)(MCR_GeneralReport_t* data)) {
    MCR_GeneralReport_status.on_receive = (void (*)(void)) callback;
}

int MCR_decode_ThermalMeasuresA_s(const uint8_t* bytes, size_t length, MCR_ThermalMeasuresA_t* data_out) {
    if (length < 8)
        return 0;

    data_out->TIGBT = bytes[0];
    data_out->TIGBTJ = bytes[1];
    data_out->TMOTCON = bytes[2];
    data_out->TMOTSEN = bytes[3];
    data_out->TMOTWIN = bytes[4];
    data_out->TCAP = bytes[5];
    data_out->TMOTI2T = bytes[6];
    return 1;
}

int MCR_decode_ThermalMeasuresA(const uint8_t* bytes, size_t length, uint8_t* TIGBT_out, uint8_t* TIGBTJ_out, uint8_t* TMOTCON_out, uint8_t* TMOTSEN_out, uint8_t* TMOTWIN_out, uint8_t* TCAP_out, uint8_t* TMOTI2T_out) {
    if (length < 8)
        return 0;

    *TIGBT_out = bytes[0];
    *TIGBTJ_out = bytes[1];
    *TMOTCON_out = bytes[2];
    *TMOTSEN_out = bytes[3];
    *TMOTWIN_out = bytes[4];
    *TCAP_out = bytes[5];
    *TMOTI2T_out = bytes[6];
    return 1;
}

int MCR_get_ThermalMeasuresA(MCR_ThermalMeasuresA_t* data_out) {
    if (!(MCR_ThermalMeasuresA_status.flags & CAN_MSG_RECEIVED))
        return 0;

    if (data_out)
        memcpy(data_out, &MCR_ThermalMeasuresA_data, sizeof(MCR_ThermalMeasuresA_t));

    int flags = MCR_ThermalMeasuresA_status.flags;
    MCR_ThermalMeasuresA_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void MCR_ThermalMeasuresA_on_receive(int (*callback)(MCR_ThermalMeasuresA_t* data)) {
    MCR_ThermalMeasuresA_status.on_receive = (void (*)(void)) callback;
}

int MCR_decode_ThermalMeasuresB_s(const uint8_t* bytes, size_t length, MCR_ThermalMeasuresB_t* data_out) {
    if (length < 8)
        return 0;

    data_out->TIGBT = bytes[0];
    data_out->TIGBTJ = bytes[1];
    data_out->TMOTCON = bytes[2];
    data_out->TMOTSEN = bytes[3];
    data_out->TMOTWIN = bytes[4];
    data_out->TCAP = bytes[5];
    data_out->TMOTI2T = bytes[6];
    return 1;
}

int MCR_decode_ThermalMeasuresB(const uint8_t* bytes, size_t length, uint8_t* TIGBT_out, uint8_t* TIGBTJ_out, uint8_t* TMOTCON_out, uint8_t* TMOTSEN_out, uint8_t* TMOTWIN_out, uint8_t* TCAP_out, uint8_t* TMOTI2T_out) {
    if (length < 8)
        return 0;

    *TIGBT_out = bytes[0];
    *TIGBTJ_out = bytes[1];
    *TMOTCON_out = bytes[2];
    *TMOTSEN_out = bytes[3];
    *TMOTWIN_out = bytes[4];
    *TCAP_out = bytes[5];
    *TMOTI2T_out = bytes[6];
    return 1;
}

int MCR_get_ThermalMeasuresB(MCR_ThermalMeasuresB_t* data_out) {
    if (!(MCR_ThermalMeasuresB_status.flags & CAN_MSG_RECEIVED))
        return 0;

    if (data_out)
        memcpy(data_out, &MCR_ThermalMeasuresB_data, sizeof(MCR_ThermalMeasuresB_t));

    int flags = MCR_ThermalMeasuresB_status.flags;
    MCR_ThermalMeasuresB_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void MCR_ThermalMeasuresB_on_receive(int (*callback)(MCR_ThermalMeasuresB_t* data)) {
    MCR_ThermalMeasuresB_status.on_receive = (void (*)(void)) callback;
}

int VDCU_decode_Status_s(const uint8_t* bytes, size_t length, VDCU_Status_t* data_out) {
    if (length < 5)
        return 0;

    data_out->State = (enum VDCU_VDCU_State) ((bytes[1] & 0x0F));
    data_out->TV_ENABLED = (bytes[2] & 0x01);
    data_out->TC_ENABLED = ((bytes[2] >> 1) & 0x01);
    data_out->YC_ENABLED = ((bytes[2] >> 2) & 0x01);
    data_out->FT_Dis_Cal = (bytes[3] & 0x01);
    data_out->FT_Sensor = ((bytes[3] >> 1) & 0x01);
    data_out->TEMP_derating = (bytes[4] & 0x01);
    data_out->ACP_derating = ((bytes[4] >> 1) & 0x01);
    data_out->Disch_ACT = ((bytes[4] >> 2) & 0x01);
    data_out->Reverse_ACT = ((bytes[4] >> 3) & 0x01);
    data_out->TC_ACT = ((bytes[4] >> 4) & 0x01);
    data_out->YC_ACT = ((bytes[4] >> 5) & 0x01);
    return 1;
}

int VDCU_decode_Status(const uint8_t* bytes, size_t length, enum VDCU_VDCU_State* State_out, uint8_t* TV_ENABLED_out, uint8_t* TC_ENABLED_out, uint8_t* YC_ENABLED_out, uint8_t* FT_Dis_Cal_out, uint8_t* FT_Sensor_out, uint8_t* TEMP_derating_out, uint8_t* ACP_derating_out, uint8_t* Disch_ACT_out, uint8_t* Reverse_ACT_out, uint8_t* TC_ACT_out, uint8_t* YC_ACT_out) {
    if (length < 5)
        return 0;

    *State_out = (enum VDCU_VDCU_State) ((bytes[1] & 0x0F));
    *TV_ENABLED_out = (bytes[2] & 0x01);
    *TC_ENABLED_out = ((bytes[2] >> 1) & 0x01);
    *YC_ENABLED_out = ((bytes[2] >> 2) & 0x01);
    *FT_Dis_Cal_out = (bytes[3] & 0x01);
    *FT_Sensor_out = ((bytes[3] >> 1) & 0x01);
    *TEMP_derating_out = (bytes[4] & 0x01);
    *ACP_derating_out = ((bytes[4] >> 1) & 0x01);
    *Disch_ACT_out = ((bytes[4] >> 2) & 0x01);
    *Reverse_ACT_out = ((bytes[4] >> 3) & 0x01);
    *TC_ACT_out = ((bytes[4] >> 4) & 0x01);
    *YC_ACT_out = ((bytes[4] >> 5) & 0x01);
    return 1;
}

int VDCU_get_Status(VDCU_Status_t* data_out) {
    if (!(VDCU_Status_status.flags & CAN_MSG_RECEIVED))
        return 0;

#ifndef CANDB_IGNORE_TIMEOUTS
    if (txGetTimeMillis() > VDCU_Status_status.timestamp + VDCU_Status_timeout)
        return 0;
#endif

    if (data_out)
        memcpy(data_out, &VDCU_Status_data, sizeof(VDCU_Status_t));

    int flags = VDCU_Status_status.flags;
    VDCU_Status_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void VDCU_Status_on_receive(int (*callback)(VDCU_Status_t* data)) {
    VDCU_Status_status.on_receive = (void (*)(void)) callback;
}

int VDCU_decode_Controller_s(const uint8_t* bytes, size_t length, VDCU_Controller_t* data_out) {
    if (length < 8)
        return 0;

    data_out->TRQ_Req = bytes[0] | bytes[1] << 8;
    data_out->TRQ_Dist_Long = bytes[2];
    data_out->TRQ_Dist_Lat = bytes[3];
    data_out->TRQ_Yaw_Req = bytes[4] | bytes[5] << 8;
    data_out->YawRate_Ref = bytes[6] | bytes[7] << 8;
    return 1;
}

int VDCU_decode_Controller(const uint8_t* bytes, size_t length, int16_t* TRQ_Req_out, uint8_t* TRQ_Dist_Long_out, int8_t* TRQ_Dist_Lat_out, int16_t* TRQ_Yaw_Req_out, int16_t* YawRate_Ref_out) {
    if (length < 8)
        return 0;

    *TRQ_Req_out = bytes[0] | bytes[1] << 8;
    *TRQ_Dist_Long_out = bytes[2];
    *TRQ_Dist_Lat_out = bytes[3];
    *TRQ_Yaw_Req_out = bytes[4] | bytes[5] << 8;
    *YawRate_Ref_out = bytes[6] | bytes[7] << 8;
    return 1;
}

int VDCU_get_Controller(VDCU_Controller_t* data_out) {
    if (!(VDCU_Controller_status.flags & CAN_MSG_RECEIVED))
        return 0;

#ifndef CANDB_IGNORE_TIMEOUTS
    if (txGetTimeMillis() > VDCU_Controller_status.timestamp + VDCU_Controller_timeout)
        return 0;
#endif

    if (data_out)
        memcpy(data_out, &VDCU_Controller_data, sizeof(VDCU_Controller_t));

    int flags = VDCU_Controller_status.flags;
    VDCU_Controller_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void VDCU_Controller_on_receive(int (*callback)(VDCU_Controller_t* data)) {
    VDCU_Controller_status.on_receive = (void (*)(void)) callback;
}

int VDCU_decode_Body_s(const uint8_t* bytes, size_t length, VDCU_Body_t* data_out) {
    if (length < 6)
        return 0;

    data_out->Speed_Ref = bytes[0] | bytes[1] << 8;
    data_out->Slip_angle = bytes[2];
    data_out->Roll = bytes[3];
    data_out->Pitch = bytes[4];
    data_out->Heave = bytes[5];
    return 1;
}

int VDCU_decode_Body(const uint8_t* bytes, size_t length, int16_t* Speed_Ref_out, int8_t* Slip_angle_out, int8_t* Roll_out, int8_t* Pitch_out, int8_t* Heave_out) {
    if (length < 6)
        return 0;

    *Speed_Ref_out = bytes[0] | bytes[1] << 8;
    *Slip_angle_out = bytes[2];
    *Roll_out = bytes[3];
    *Pitch_out = bytes[4];
    *Heave_out = bytes[5];
    return 1;
}

int VDCU_get_Body(VDCU_Body_t* data_out) {
    if (!(VDCU_Body_status.flags & CAN_MSG_RECEIVED))
        return 0;

#ifndef CANDB_IGNORE_TIMEOUTS
    if (txGetTimeMillis() > VDCU_Body_status.timestamp + VDCU_Body_timeout)
        return 0;
#endif

    if (data_out)
        memcpy(data_out, &VDCU_Body_data, sizeof(VDCU_Body_t));

    int flags = VDCU_Body_status.flags;
    VDCU_Body_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void VDCU_Body_on_receive(int (*callback)(VDCU_Body_t* data)) {
    VDCU_Body_status.on_receive = (void (*)(void)) callback;
}

int VDCU_decode_WheelFz_s(const uint8_t* bytes, size_t length, VDCU_WheelFz_t* data_out) {
    if (length < 8)
        return 0;

    data_out->FR = bytes[0] | bytes[1] << 8;
    data_out->FL = bytes[2] | bytes[3] << 8;
    data_out->RR = bytes[4] | bytes[5] << 8;
    data_out->RL = bytes[6] | bytes[7] << 8;
    return 1;
}

int VDCU_decode_WheelFz(const uint8_t* bytes, size_t length, uint16_t* FR_out, uint16_t* FL_out, uint16_t* RR_out, uint16_t* RL_out) {
    if (length < 8)
        return 0;

    *FR_out = bytes[0] | bytes[1] << 8;
    *FL_out = bytes[2] | bytes[3] << 8;
    *RR_out = bytes[4] | bytes[5] << 8;
    *RL_out = bytes[6] | bytes[7] << 8;
    return 1;
}

int VDCU_get_WheelFz(VDCU_WheelFz_t* data_out) {
    if (!(VDCU_WheelFz_status.flags & CAN_MSG_RECEIVED))
        return 0;

#ifndef CANDB_IGNORE_TIMEOUTS
    if (txGetTimeMillis() > VDCU_WheelFz_status.timestamp + VDCU_WheelFz_timeout)
        return 0;
#endif

    if (data_out)
        memcpy(data_out, &VDCU_WheelFz_data, sizeof(VDCU_WheelFz_t));

    int flags = VDCU_WheelFz_status.flags;
    VDCU_WheelFz_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void VDCU_WheelFz_on_receive(int (*callback)(VDCU_WheelFz_t* data)) {
    VDCU_WheelFz_status.on_receive = (void (*)(void)) callback;
}

int VDCU_send_Param_s(const VDCU_Param_t* data) {
    uint8_t buffer[5];
    buffer[0] = data->Param_ID;
    buffer[1] = data->Param;
    buffer[2] = (data->Param >> 8);
    buffer[3] = data->SEQ_PARAM;
    buffer[4] = ((data->SEQ & 0x0F) << 4);
    int rc = txSendCANMessage(VDCU_Param_id, buffer, sizeof(buffer));

    if (rc == 0) {
        VDCU_Param_last_sent = txGetTimeMillis();
    }

    return rc;
}

int VDCU_send_Param(enum VDCU_VDCU_Param Param_ID, int16_t Param, uint8_t SEQ_PARAM, uint8_t SEQ) {
    uint8_t buffer[5];
    buffer[0] = Param_ID;
    buffer[1] = Param;
    buffer[2] = (Param >> 8);
    buffer[3] = SEQ_PARAM;
    buffer[4] = ((SEQ & 0x0F) << 4);
    int rc = txSendCANMessage(VDCU_Param_id, buffer, sizeof(buffer));

    if (rc == 0) {
        VDCU_Param_last_sent = txGetTimeMillis();
    }

    return rc;
}

int VDCU_Param_need_to_send(void) {
    return (VDCU_Param_last_sent == -1) || (txGetTimeMillis() >= VDCU_Param_last_sent + 20);
}

int VDCU_decode_Param_ACK_s(const uint8_t* bytes, size_t length, VDCU_Param_ACK_t* data_out) {
    if (length < 4)
        return 0;

    data_out->Param_ID = bytes[0];
    data_out->Param = bytes[1] | bytes[2] << 8;
    data_out->SEQ_Param = bytes[3];
    return 1;
}

int VDCU_decode_Param_ACK(const uint8_t* bytes, size_t length, uint8_t* Param_ID_out, int16_t* Param_out, uint8_t* SEQ_Param_out) {
    if (length < 4)
        return 0;

    *Param_ID_out = bytes[0];
    *Param_out = bytes[1] | bytes[2] << 8;
    *SEQ_Param_out = bytes[3];
    return 1;
}

int VDCU_get_Param_ACK(VDCU_Param_ACK_t* data_out) {
    if (!(VDCU_Param_ACK_status.flags & CAN_MSG_RECEIVED))
        return 0;

#ifndef CANDB_IGNORE_TIMEOUTS
    if (txGetTimeMillis() > VDCU_Param_ACK_status.timestamp + VDCU_Param_ACK_timeout)
        return 0;
#endif

    if (data_out)
        memcpy(data_out, &VDCU_Param_ACK_data, sizeof(VDCU_Param_ACK_t));

    int flags = VDCU_Param_ACK_status.flags;
    VDCU_Param_ACK_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void VDCU_Param_ACK_on_receive(int (*callback)(VDCU_Param_ACK_t* data)) {
    VDCU_Param_ACK_status.on_receive = (void (*)(void)) callback;
}

int VDCU_send_REQCalibDis_s(const VDCU_REQCalibDis_t* data) {
    uint8_t buffer[5];
    buffer[0] = (data->which & 0x0F);
    buffer[1] = data->load;
    buffer[2] = (data->load >> 8);
    buffer[3] = data->scale;
    buffer[4] = (data->scale >> 8);
    int rc = txSendCANMessage(VDCU_REQCalibDis_id, buffer, sizeof(buffer));
    return rc;
}

int VDCU_send_REQCalibDis(enum VDCU_CAL_DisIndex which, int16_t load, int16_t scale) {
    uint8_t buffer[5];
    buffer[0] = (which & 0x0F);
    buffer[1] = load;
    buffer[2] = (load >> 8);
    buffer[3] = scale;
    buffer[4] = (scale >> 8);
    int rc = txSendCANMessage(VDCU_REQCalibDis_id, buffer, sizeof(buffer));
    return rc;
}

int VDCU_decode_SOC_s(const uint8_t* bytes, size_t length, VDCU_SOC_t* data_out) {
    if (length < 1)
        return 0;

    data_out->SOC = bytes[0];
    return 1;
}

int VDCU_decode_SOC(const uint8_t* bytes, size_t length, uint8_t* SOC_out) {
    if (length < 1)
        return 0;

    *SOC_out = bytes[0];
    return 1;
}

int VDCU_get_SOC(VDCU_SOC_t* data_out) {
    if (!(VDCU_SOC_status.flags & CAN_MSG_RECEIVED))
        return 0;

#ifndef CANDB_IGNORE_TIMEOUTS
    if (txGetTimeMillis() > VDCU_SOC_status.timestamp + VDCU_SOC_timeout)
        return 0;
#endif

    if (data_out)
        memcpy(data_out, &VDCU_SOC_data, sizeof(VDCU_SOC_t));

    int flags = VDCU_SOC_status.flags;
    VDCU_SOC_status.flags &= ~CAN_MSG_PENDING;
    return flags;
}

void VDCU_SOC_on_receive(int (*callback)(VDCU_SOC_t* data)) {
    VDCU_SOC_status.on_receive = (void (*)(void)) callback;
}

void candbHandleMessage(uint32_t timestamp, CAN_ID_t id, const uint8_t* payload, size_t payload_length) {
    switch (id) {
    case ECUA_Status_id: {
        if (!ECUA_decode_Status_s(payload, payload_length, &ECUA_Status_data))
            break;

        canUpdateMsgStatusOnReceive(&ECUA_Status_status, timestamp);

        if (ECUA_Status_status.on_receive)
            ((int (*)(ECUA_Status_t*)) ECUA_Status_status.on_receive)(&ECUA_Status_data);

        break;
    }
    case ECUA_Limits_id: {
        if (!ECUA_decode_Limits_s(payload, payload_length, &ECUA_Limits_data))
            break;

        canUpdateMsgStatusOnReceive(&ECUA_Limits_status, timestamp);

        if (ECUA_Limits_status.on_receive)
            ((int (*)(ECUA_Limits_t*)) ECUA_Limits_status.on_receive)(&ECUA_Limits_data);

        break;
    }
    case ECUA_ACPMeas_id: {
        if (!ECUA_decode_ACPMeas_s(payload, payload_length, &ECUA_ACPMeas_data))
            break;

        canUpdateMsgStatusOnReceive(&ECUA_ACPMeas_status, timestamp);

        if (ECUA_ACPMeas_status.on_receive)
            ((int (*)(ECUA_ACPMeas_t*)) ECUA_ACPMeas_status.on_receive)(&ECUA_ACPMeas_data);

        break;
    }
    case ECUA_Estimation_id: {
        if (!ECUA_decode_Estimation_s(payload, payload_length, &ECUA_Estimation_data))
            break;

        canUpdateMsgStatusOnReceive(&ECUA_Estimation_status, timestamp);

        if (ECUA_Estimation_status.on_receive)
            ((int (*)(ECUA_Estimation_t*)) ECUA_Estimation_status.on_receive)(&ECUA_Estimation_data);

        break;
    }
    case ECUA_AMSOverall_id: {
        if (!ECUA_decode_AMSOverall_s(payload, payload_length, &ECUA_AMSOverall_data))
            break;

        canUpdateMsgStatusOnReceive(&ECUA_AMSOverall_status, timestamp);

        if (ECUA_AMSOverall_status.on_receive)
            ((int (*)(ECUA_AMSOverall_t*)) ECUA_AMSOverall_status.on_receive)(&ECUA_AMSOverall_data);

        break;
    }
    case ECUB_Status_id: {
        if (!ECUB_decode_Status_s(payload, payload_length, &ECUB_Status_data))
            break;

        canUpdateMsgStatusOnReceive(&ECUB_Status_status, timestamp);

        if (ECUB_Status_status.on_receive)
            ((int (*)(ECUB_Status_t*)) ECUB_Status_status.on_receive)(&ECUB_Status_data);

        break;
    }
    case ECUB_Cooling_id: {
        if (!ECUB_decode_Cooling_s(payload, payload_length, &ECUB_Cooling_data))
            break;

        canUpdateMsgStatusOnReceive(&ECUB_Cooling_status, timestamp);

        if (ECUB_Cooling_status.on_receive)
            ((int (*)(ECUB_Cooling_t*)) ECUB_Cooling_status.on_receive)(&ECUB_Cooling_data);

        break;
    }
    case ECUB_TEMPSuspR_id: {
        if (!ECUB_decode_TEMPSuspR_s(payload, payload_length, &ECUB_TEMPSuspR_data))
            break;

        canUpdateMsgStatusOnReceive(&ECUB_TEMPSuspR_status, timestamp);

        if (ECUB_TEMPSuspR_status.on_receive)
            ((int (*)(ECUB_TEMPSuspR_t*)) ECUB_TEMPSuspR_status.on_receive)(&ECUB_TEMPSuspR_data);

        break;
    }
    case ECUB_TEMPAux_id: {
        if (!ECUB_decode_TEMPAux_s(payload, payload_length, &ECUB_TEMPAux_data))
            break;

        canUpdateMsgStatusOnReceive(&ECUB_TEMPAux_status, timestamp);

        if (ECUB_TEMPAux_status.on_receive)
            ((int (*)(ECUB_TEMPAux_t*)) ECUB_TEMPAux_status.on_receive)(&ECUB_TEMPAux_data);

        break;
    }
    case ECUF_Status_id: {
        if (!ECUF_decode_Status_s(payload, payload_length, &ECUF_Status_data))
            break;

        canUpdateMsgStatusOnReceive(&ECUF_Status_status, timestamp);

        if (ECUF_Status_status.on_receive)
            ((int (*)(ECUF_Status_t*)) ECUF_Status_status.on_receive)(&ECUF_Status_data);

        break;
    }
    case ECUF_STW_id: {
        if (!ECUF_decode_STW_s(payload, payload_length, &ECUF_STW_data))
            break;

        canUpdateMsgStatusOnReceive(&ECUF_STW_status, timestamp);

        if (ECUF_STW_status.on_receive)
            ((int (*)(ECUF_STW_t*)) ECUF_STW_status.on_receive)(&ECUF_STW_data);

        break;
    }
    case ECUF_TEMPSuspF_id: {
        if (!ECUF_decode_TEMPSuspF_s(payload, payload_length, &ECUF_TEMPSuspF_data))
            break;

        canUpdateMsgStatusOnReceive(&ECUF_TEMPSuspF_status, timestamp);

        if (ECUF_TEMPSuspF_status.on_receive)
            ((int (*)(ECUF_TEMPSuspF_t*)) ECUF_TEMPSuspF_status.on_receive)(&ECUF_TEMPSuspF_data);

        break;
    }
    case ECUP_Status_id: {
        if (!ECUP_decode_Status_s(payload, payload_length, &ECUP_Status_data))
            break;

        canUpdateMsgStatusOnReceive(&ECUP_Status_status, timestamp);

        if (ECUP_Status_status.on_receive)
            ((int (*)(ECUP_Status_t*)) ECUP_Status_status.on_receive)(&ECUP_Status_data);

        break;
    }
    case ECUP_Pedals_id: {
        if (!ECUP_decode_Pedals_s(payload, payload_length, &ECUP_Pedals_data))
            break;

        canUpdateMsgStatusOnReceive(&ECUP_Pedals_status, timestamp);

        if (ECUP_Pedals_status.on_receive)
            ((int (*)(ECUP_Pedals_t*)) ECUP_Pedals_status.on_receive)(&ECUP_Pedals_data);

        break;
    }
    case ECUP_Pressure_id: {
        if (!ECUP_decode_Pressure_s(payload, payload_length, &ECUP_Pressure_data))
            break;

        canUpdateMsgStatusOnReceive(&ECUP_Pressure_status, timestamp);

        if (ECUP_Pressure_status.on_receive)
            ((int (*)(ECUP_Pressure_t*)) ECUP_Pressure_status.on_receive)(&ECUP_Pressure_data);

        break;
    }
    case ECUP_DiagPos_id: {
        if (!ECUP_decode_DiagPos_s(payload, payload_length, &ECUP_DiagPos_data))
            break;

        canUpdateMsgStatusOnReceive(&ECUP_DiagPos_status, timestamp);

        if (ECUP_DiagPos_status.on_receive)
            ((int (*)(ECUP_DiagPos_t*)) ECUP_DiagPos_status.on_receive)(&ECUP_DiagPos_data);

        break;
    }
    case IMU_Status_id: {
        if (!IMU_decode_Status_s(payload, payload_length, &IMU_Status_data))
            break;

        canUpdateMsgStatusOnReceive(&IMU_Status_status, timestamp);

        if (IMU_Status_status.on_receive)
            ((int (*)(IMU_Status_t*)) IMU_Status_status.on_receive)(&IMU_Status_data);

        break;
    }
    case MCR_GeneralReport_id: {
        if (!MCR_decode_GeneralReport_s(payload, payload_length, &MCR_GeneralReport_data))
            break;

        canUpdateMsgStatusOnReceive(&MCR_GeneralReport_status, timestamp);

        if (MCR_GeneralReport_status.on_receive)
            ((int (*)(MCR_GeneralReport_t*)) MCR_GeneralReport_status.on_receive)(&MCR_GeneralReport_data);

        break;
    }
    case MCR_ThermalMeasuresA_id: {
        if (!MCR_decode_ThermalMeasuresA_s(payload, payload_length, &MCR_ThermalMeasuresA_data))
            break;

        canUpdateMsgStatusOnReceive(&MCR_ThermalMeasuresA_status, timestamp);

        if (MCR_ThermalMeasuresA_status.on_receive)
            ((int (*)(MCR_ThermalMeasuresA_t*)) MCR_ThermalMeasuresA_status.on_receive)(&MCR_ThermalMeasuresA_data);

        break;
    }
    case MCR_ThermalMeasuresB_id: {
        if (!MCR_decode_ThermalMeasuresB_s(payload, payload_length, &MCR_ThermalMeasuresB_data))
            break;

        canUpdateMsgStatusOnReceive(&MCR_ThermalMeasuresB_status, timestamp);

        if (MCR_ThermalMeasuresB_status.on_receive)
            ((int (*)(MCR_ThermalMeasuresB_t*)) MCR_ThermalMeasuresB_status.on_receive)(&MCR_ThermalMeasuresB_data);

        break;
    }
    case VDCU_Status_id: {
        if (!VDCU_decode_Status_s(payload, payload_length, &VDCU_Status_data))
            break;

        canUpdateMsgStatusOnReceive(&VDCU_Status_status, timestamp);

        if (VDCU_Status_status.on_receive)
            ((int (*)(VDCU_Status_t*)) VDCU_Status_status.on_receive)(&VDCU_Status_data);

        break;
    }
    case VDCU_Controller_id: {
        if (!VDCU_decode_Controller_s(payload, payload_length, &VDCU_Controller_data))
            break;

        canUpdateMsgStatusOnReceive(&VDCU_Controller_status, timestamp);

        if (VDCU_Controller_status.on_receive)
            ((int (*)(VDCU_Controller_t*)) VDCU_Controller_status.on_receive)(&VDCU_Controller_data);

        break;
    }
    case VDCU_Body_id: {
        if (!VDCU_decode_Body_s(payload, payload_length, &VDCU_Body_data))
            break;

        canUpdateMsgStatusOnReceive(&VDCU_Body_status, timestamp);

        if (VDCU_Body_status.on_receive)
            ((int (*)(VDCU_Body_t*)) VDCU_Body_status.on_receive)(&VDCU_Body_data);

        break;
    }
    case VDCU_WheelFz_id: {
        if (!VDCU_decode_WheelFz_s(payload, payload_length, &VDCU_WheelFz_data))
            break;

        canUpdateMsgStatusOnReceive(&VDCU_WheelFz_status, timestamp);

        if (VDCU_WheelFz_status.on_receive)
            ((int (*)(VDCU_WheelFz_t*)) VDCU_WheelFz_status.on_receive)(&VDCU_WheelFz_data);

        break;
    }
    case VDCU_Param_ACK_id: {
        if (!VDCU_decode_Param_ACK_s(payload, payload_length, &VDCU_Param_ACK_data))
            break;

        canUpdateMsgStatusOnReceive(&VDCU_Param_ACK_status, timestamp);

        if (VDCU_Param_ACK_status.on_receive)
            ((int (*)(VDCU_Param_ACK_t*)) VDCU_Param_ACK_status.on_receive)(&VDCU_Param_ACK_data);

        break;
    }
    case VDCU_SOC_id: {
        if (!VDCU_decode_SOC_s(payload, payload_length, &VDCU_SOC_data))
            break;

        canUpdateMsgStatusOnReceive(&VDCU_SOC_status, timestamp);

        if (VDCU_SOC_status.on_receive)
            ((int (*)(VDCU_SOC_t*)) VDCU_SOC_status.on_receive)(&VDCU_SOC_data);

        break;
    }
    }
}
