package kr.kro.es7.smartfarm;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;

import java.util.Optional;

public interface SensorRepository extends JpaRepository<SensorData, Long> {

    @Query(value = "SELECT * FROM sensor_data WHERE id = (SELECT MAX(id) FROM sensor_data)", nativeQuery = true)
    Optional<SensorData> findLastData();
}
