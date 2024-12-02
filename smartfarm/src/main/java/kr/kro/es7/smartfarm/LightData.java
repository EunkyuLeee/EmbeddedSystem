package kr.kro.es7.smartfarm;

import com.fasterxml.jackson.annotation.JsonProperty;
import jakarta.persistence.*;
import lombok.*;

@Entity(name = "light_data")
@Getter
@Setter
@ToString
@NoArgsConstructor
@AllArgsConstructor
public class LightData {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(name = "light_value")
    @JsonProperty("light_value")
    private String light_value;
}
