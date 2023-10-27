#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>

#define MPU6050_ADDRESS (0x68) // MPU6050 I2C address

Adafruit_MPU6050 mpu;
unsigned long startTime;
void setup() {
  startTime = millis();
  Serial.begin(9600);
  while (!Serial) {
    delay(10);
  }

  Wire.begin();

  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
}

void loop() {
  sensors_event_t accel;
  sensors_event_t gyro;
  unsigned long currentTime = millis();
  unsigned long elapsedTime = currentTime - startTime;

  mpu.getAccelerometerSensor()->getEvent(&accel);
mpu.getGyroSensor()->getEvent(&gyro);

  Serial.print("Accelerometer (m/s^2): ");
  Serial.print(accel.acceleration.x);
  Serial.print(",");
  Serial.print(accel.acceleration.y);
  Serial.print(",");
  Serial.println(accel.acceleration.z);
  Serial.print("Gyroscope (deg/s): ");
  Serial.print(gyro.gyro.x);
  Serial.print(",");
  Serial.print(gyro.gyro.y);
  Serial.print(",");
  Serial.println(gyro.gyro.z);
  Serial.print("Time: ");
  Serial.println(elapsedTime);




  delay(600); // adjust as needed
}
