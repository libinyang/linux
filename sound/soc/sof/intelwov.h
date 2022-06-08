#ifndef __SOUND_SOC_SOF_INTELWOV_H
#define __SOUND_SOC_SOF_INTELWOV_H

enum IntelWovParams
{
    //! Parameter for configuring WoV model.
    /*!
      \see IntelWovCfgBlobHeader
    */
    INTEL_WOV_PP_CONFIG_PARAM_NEWBLOB = 2,

    //! Parameter for enabling/disabling active models (key phrases).
    INTEL_WOV_PP_CONFIG_PARAM_ACTIVE_MASK = 3,

    //! Get debug data form intel wov module.
    INTEL_WOV_PP_DEBUG_DATA = 100,
};

#define INTEL_WOV_CFG_BLOB_SIG	0xaa550002

struct intelwov_modelcfg
{
    //! ID of model.
    uint32_t model_id;
    //! Key Phrase Detection (KPD) Sensitivity.
    uint32_t kpd_sensitivity;
    //! Key Phrase Buffering (KPB) Module output pin.
    uint32_t kpbuf_out_pin;
    //! Key Phrase Buffering (KPB) Onset buffer size
    uint32_t history_buffer_size_idle;
    //! Key Phrase Buffering (KPB) Max history buffer size
    uint32_t history_buffer_size_max;
};

struct intelwov_cfgblobheader2
{
    //! Must be #INTEL_WOV_CFG_BLOB_SIG.
    uint32_t         signature;
    //! Size of configuration blob in bytes.
    uint32_t         config_glob_size;
    //! Number of models (determines length of #model_cfg).
    uint32_t         model_count;
    //! Array of models descriptions and its connection to KPB.
    struct intelwov_modelcfg model_cfg[0];
};


#endif
