#include <stdint.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include "quantum.h"
#include "raw_hid.h"
#include "via.h"

typedef uint8_t gpk_rc_command_id_t;

enum gpk_rc_command_ids {
  id_gpk_rc_set_value                  = 0x01,
  id_gpk_rc_get_value                  = 0x02,
  id_gpk_rc_operation                  = 0x03,
};

typedef struct {
  gpk_rc_command_id_t id;
  uint8_t action;
  uint32_t data_length;
  uint8_t* data;
} gpk_rc_command_t;

extern bool use_gpk_rc_custom_receive;
void gpk_rc_handle_command_user(uint8_t id, uint8_t action, uint8_t *data, uint8_t length);
void gpk_rc_on_receive(uint8_t* data, uint8_t data_length);
