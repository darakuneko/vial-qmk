#include <stdint.h>
#include <sys/types.h>

typedef uint8_t gpk_rc_command_id_t;

typedef union {
  uint32_t data_length;
  uint8_t raw[4];
} gpk_rc_data_length_t;

typedef enum {
  RECEIVING_COMMAND,
  RECEIVING_DATA_LENGTH,
  RECEIVING_DATA,
} gpk_rc_parser_state_t;

typedef struct {
  gpk_rc_parser_state_t state;
  uint8_t data_length_bytes_read;
  uint32_t data_bytes_read;
  gpk_rc_data_length_t data_length;
} gpk_rc_parser_t;

typedef struct {
  gpk_rc_command_id_t id;
  uint32_t data_length;
  uint8_t* data;
} gpk_rc_command_t;

void gpk_rc_receive(uint8_t *buffer, uint16_t max_buffer_length, uint8_t* data, uint8_t data_length);
