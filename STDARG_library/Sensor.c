#include <stdio.h>
#include <stdarg.h>

/*định nghĩa một kiểu liệt kê (enum) tên là SensorType. 
Kiểu này được sử dụng để xác định loại cảm biến mà hàm processSensorData sẽ xử lý.*/
typedef enum {
    TEMPERATURE_SENSOR,
    PRESSURE_SENSOR,
    HUMIDITY_SENSOR
} SensorType;

/* Macro để xử lý các cảm biến chung 
+, type là kiểu dữ liệu của giá trị cảm biến (float, int, v.v.).
+, format là chuỗi định dạng (printf) cho việc in ra kết quả.
+, ... là các tham số truyền vào hàm phụ thuộc vào người dùng
+, va_arg(args, int) lấy tham số tiếp theo từ danh sách tham số biến (va_list), ở đây là numArgs và sensorId.
+, type reading = va_arg(args, type); lấy giá trị cảm biến từ danh sách tham số.
+, printf(format, sensorId, reading); in ra kết quả của cảm biến, sử dụng định dạng được truyền vào.
*/ 
#define PROCESS_SENSOR(type, format, ...) \
    int numArgs = va_arg(args, int); \
    int sensorId = va_arg(args, int); \
    type reading = va_arg(args, type); \
    printf(format, sensorId, reading); \
    switch (numArgs) { \
        case 3: { \
            char* info = va_arg(args, char*); \
            printf("Info: %s\n", info); \
            break; \
        } \
        case 4: { \
            char* info1 = va_arg(args, char*); \
            char* info2 = va_arg(args, char*); \
            printf("Info 1: %s\n", info1); \
            printf("Info 2: %s\n", info2); \
            break; \
        } \
        default: \
            break; \
    }

/* Hàm này xử lý dữ liệu của các loại cảm biến khác nhau dựa trên type (loại cảm biến) được truyền vào.
+, va_list args; và va_start(args, type); được sử dụng để truy cập các tham số biến được truyền vào hàm. */

void processSensorData(SensorType type, ...) {
    va_list args;
    va_start(args, type);

    switch (type) {
        case TEMPERATURE_SENSOR: {
            PROCESS_SENSOR(double, "Temperature Sensor ID: %d, Reading: %.2f degrees\n")
            break;
        }
        case PRESSURE_SENSOR: {
            PROCESS_SENSOR(int, "Pressure Sensor ID: %d, Reading: %d Pa\n")
            break;
        }
        case HUMIDITY_SENSOR: {
            PROCESS_SENSOR(int, "Humidity Sensor ID: %d, Reading: %d phantram\n")
            break;
        }
    }

    va_end(args);
}

int main() {
    processSensorData(TEMPERATURE_SENSOR, 3, 1, 36.5, "Room Temperature");
    processSensorData(PRESSURE_SENSOR, 4, 2, 101325, "Sea Level", "Atmospheric Pressure");
    processSensorData(HUMIDITY_SENSOR, 3, 3, 80, "Indoor");
    return 0;
}