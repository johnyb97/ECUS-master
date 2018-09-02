#ifndef _I2C_LIB
	#define _I2C_LIB
	#include "config.h"
	#include "circular_buffer.h"

	#define I2C_F_400k	0x00401959ul
	#define I2C_F_100k	0x00C0EAFFul

	typedef enum {
		I2C_W=0,
		I2C_R=1
	}I2C_RW_t;

	typedef struct{
		void(*callback)(void *arg);
		void *arg;
		enum{
			I2C_TASK_START,
			I2C_TASK_WRITE,
			I2C_TASK_READ,
			I2C_TASK_IDLE,
		}type;
		// uint8_t id;
		union{
			struct{
				union{
					const uint8_t *w;
					uint8_t *r;	
				}data;
				uint8_t bytes;
				bool close;
				bool start_workaround;
			}rw;
			struct{
				uint8_t address;
				bool write;
			}start;
		}task_specific;
	}i2c_task_t;

	typedef struct{
		I2C_TypeDef *dev;
		circular_buffer_t *cb;
		volatile i2c_task_t current_task;
		volatile uint8_t stops_queued;//holds amount of ready to send(start,data,_STOP_) sequences in buffer
	}i2c_handle_t;



	//void i2c_init(I2C_TypeDef *dev, uint32_t tcfg);
	void i2c_add_task(i2c_handle_t *handle, i2c_task_t *task);
	void i2c_irq_handler(i2c_handle_t *handle);
	void i2c_init(i2c_handle_t *handle, uint32_t tcfg);
	void i2c_next_task(i2c_handle_t *handle);


	void i2c_add_task_write_ext(i2c_handle_t *handle, const uint8_t *data, const uint8_t length, const bool close, void(*callback)(void *arg), void *callback_arg);
	static inline void i2c_add_task_write(i2c_handle_t *handle, const uint8_t *data, const uint8_t length, const bool close)
		{i2c_add_task_write_ext(handle, data, length, close, NULL, NULL);};

	void i2c_add_task_read_ext(i2c_handle_t *handle, uint8_t *data, const uint8_t length, const bool close, void(*callback)(void *arg), void *callback_arg);
	static inline void i2c_add_task_read(i2c_handle_t *handle, uint8_t *data, const uint8_t length, const bool close)
		{i2c_add_task_read_ext(handle, data, length, close, NULL, NULL);}
	
	void i2c_add_task_start_ext(i2c_handle_t *handle, const uint8_t address, const bool write, void(*callback)(void *arg), void *callback_arg);
	static inline void i2c_add_task_start(i2c_handle_t *handle, const uint8_t address, const bool write)
		{i2c_add_task_start_ext(handle, address, write, NULL, NULL);};
	static inline void i2c_add_task_start_read(i2c_handle_t *handle, const uint8_t address)
		{i2c_add_task_start(handle, address, false);};
	static inline void i2c_add_task_start_write(i2c_handle_t *handle, const uint8_t address)
		{i2c_add_task_start(handle, address, true);};
#endif