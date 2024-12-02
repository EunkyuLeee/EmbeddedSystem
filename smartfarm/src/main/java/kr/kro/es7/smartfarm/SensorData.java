package kr.kro.es7.smartfarm;

import com.fasterxml.jackson.annotation.JsonProperty;
import jakarta.persistence.*;
import lombok.*;

@Entity(name = "sensor_data")
@Getter
@Setter
@ToString
@NoArgsConstructor
@AllArgsConstructor
public class SensorData {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(name = "temperature")
    @JsonProperty("temperature")
    private int temperature;
    @Column(name = "humidity")
    @JsonProperty("humidity")
    private int humidity;
    @Column(name = "brightness")
    @JsonProperty("brightness")
    private int brightness;
    @Column(name = "co2")
    @JsonProperty("co2")
    private int co2;
    @Column(name = "soil_moisture")
    @JsonProperty("soil_moisture")
    private int soilMoisture;
    @Column(name = "intrusion")
    @JsonProperty("intrusion")
    private String intrusion;
}
