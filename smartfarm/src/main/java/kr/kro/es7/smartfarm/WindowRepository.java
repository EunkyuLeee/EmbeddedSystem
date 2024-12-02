package kr.kro.es7.smartfarm;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;

import java.util.Optional;

public interface WindowRepository extends JpaRepository<WindowData, Long> {
    @Query(value = "SELECT window_value FROM window_data WHERE id = (SELECT MAX(id) FROM window_data)", nativeQuery = true)
    Optional<String> findLastData();
}
