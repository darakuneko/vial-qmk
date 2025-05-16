#include "gpk_rc.h"

#define GPK_RC_BUFFER_MAX 64
static uint8_t gpk_rc_buffer[GPK_RC_BUFFER_MAX] = {};
bool use_gpk_rc_custom_receive = false;

static void gpk_rc_parse_command(uint8_t *buffer, uint8_t* data, uint8_t data_length);

__attribute__((weak)) void gpk_rc_handle_command_user(uint8_t id, uint8_t action, uint8_t *data, uint8_t length) {}

gpk_rc_command_t command = {
  .id = UINT8_MAX,
  .action = UINT8_MAX,
  .data_length = 0,
  .data = NULL,
};
  
static void gpk_rc_handle_command_quantum(gpk_rc_command_t* command) {
  switch (command->id) {
    case id_gpk_rc_set_value:
    case id_gpk_rc_get_value:
    case id_gpk_rc_operation: {
      gpk_rc_handle_command_user(
        command->id,
        command->action,
        command->data,
        command->data_length
      );
      break;
    }
    default:
      break;
  }
} 

void gpk_rc_on_receive(uint8_t* data, uint8_t data_length) {
  gpk_rc_parse_command(gpk_rc_buffer, data, data_length);
}

static void gpk_rc_parse_command(uint8_t *buffer, uint8_t* data, uint8_t data_length) {
  use_gpk_rc_custom_receive = true;
  if (data_length == 0) return;
  command.id = data[0];
  command.action = data[1];
  command.data_length = data_length - 2;

  if (command.data_length > 0) {
    if (command.data_length <= GPK_RC_BUFFER_MAX) {
      memcpy(buffer, &data[2], command.data_length);
      command.data = buffer;
    } else {
      return;
    }
  } else {
    command.data = NULL;
  }
  
  gpk_rc_handle_command_quantum(&command);
}