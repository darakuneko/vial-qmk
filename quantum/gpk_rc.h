#include <stdint.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include "quantum.h"
#include "raw_hid.h"
#include "via.h"

typedef uint8_t gpk_rc_command_id_t;

enum gpk_rc_command_ids {
  id_gpk_rc_info                       = 0x01,
  id_gpk_rc_custom_set_value           = 0x02,
  id_gpk_rc_custom_get_value           = 0x03,
  id_gpk_rc_layer_move                 = 0x04,
  id_gpk_rc_olde_write                 = 0x05,
  id_gpk_rc_pomodoro_get_value         = 0x06
};
 
typedef struct {
  uint8_t version;
  char device[12];
} gpk_rc_info_t;

typedef union {
  uint32_t data_length;
  uint8_t raw[4];
} gpk_rc_data_length_t;

typedef struct {
  gpk_rc_command_id_t id;
  uint32_t data_length;
  uint8_t* data;
} gpk_rc_command_t;

extern bool use_gpk_rc_custom_receive;
void gpk_rc_handle_command_user(uint8_t id, uint8_t *data, uint8_t length);
void gpk_rc_on_receive(uint8_t* data, uint8_t data_length);
