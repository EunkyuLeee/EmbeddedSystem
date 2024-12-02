package kr.kro.es7.smartfarm;

import com.fasterxml.jackson.annotation.JsonProperty;
import jakarta.persistence.*;
import lombok.*;

@Entity(name = "window_data")
@Getter
@Setter
@ToString
@NoArgsConstructor
@AllArgsConstructor
public class WindowData {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(name = "window_value")
    @JsonProperty("window_value")
    private String window_value;
}
