#include <esp_now.h>
#include <WiFi.h>
#include <math.h>

// Define number of clusters and features
#define N_CLUSTERS 2
#define N_FEATURES 2

// Centroids of the KMeans model (from your trained model)
float centroids[N_CLUSTERS][N_FEATURES] = {
    {-0.10482739, -0.77115239},  // Cluster 1
    { 0.14144518,  1.04052753}   // Cluster 2
};

// Structure to hold sensor data
typedef struct struct_message {
  uint8_t nodeID;          // Unique ID for each node
  float temperature;
  float accelX;
  float accelY;
  float accelZ;
} struct_message;

struct_message receivedData;

// Function to calculate Euclidean distance between two points
float euclidean_distance(float* point1, float* point2) {
    float distance = 0.0;
    for (int i = 0; i < N_FEATURES; i++) {
        distance += (point1[i] - point2[i]) * (point1[i] - point2[i]);
    }
    return sqrt(distance);
}

// Function to predict the cluster for a new data point
int predict_cluster(float* new_point) {
    int closest_cluster = 0;
    float min_distance = euclidean_distance(new_point, centroids[0]);
    
    for (int i = 1; i < N_CLUSTERS; i++) {
        float distance = euclidean_distance(new_point, centroids[i]);
        if (distance < min_distance) {
            min_distance = distance;
            closest_cluster = i;
        }
    }
    return closest_cluster;
}

// Callback function to handle received data
void onDataRecv(const esp_now_recv_info* recv_info, const uint8_t *data, int len) {
  // Copy received data into the structure
  memcpy(&receivedData, data, sizeof(receivedData));

  // Calculate the acceleration magnitude
  float accel_magnitude = sqrt(pow(receivedData.accelX, 2) + pow(receivedData.accelY, 2) + pow(receivedData.accelZ, 2));
  float features[N_FEATURES] = {receivedData.temperature, accel_magnitude};

  // Predict cluster for the received data point
  int predicted_cluster = predict_cluster(features);

  // Print received data and prediction result
  Serial.print("Node ID: ");
  Serial.println(receivedData.nodeID);
  Serial.print("Temperature: ");
  Serial.println(receivedData.temperature);
  
  // Print calculated acceleration magnitude instead of individual acceleration values
  Serial.print("Acceleration Magnitude: ");
  Serial.println(accel_magnitude);
  
  Serial.print("Predicted Cluster: ");
  Serial.println(predicted_cluster == 0 ? "Normal" : "Anomaly");
  Serial.println();
}

void setup() {
  Serial.begin(115200);

  // Initialize WiFi in Station mode
  WiFi.mode(WIFI_STA);

  // Initialize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Register the receive callback function
  esp_now_register_recv_cb(onDataRecv);
  
  Serial.println("Gateway initialized and waiting for data...");
}

void loop() {
  // Nothing to do here, just wait for incoming data
  delay(1000);
}
