package kr.kro.es7.smartfarm;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;

import java.util.Optional;

public interface LightRepository extends JpaRepository<LightData, Long> {
    @Query(value = "SELECT light_value FROM light_data WHERE id = (SELECT MAX(id) FROM light_data)", nativeQuery = true)
    Optional<String> findLastData();
}
