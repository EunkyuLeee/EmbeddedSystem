package kr.kro.es7.smartfarm;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Optional;

@Service
public class SensorService {

    @Autowired
    private SensorRepository sensorRepository;

    public void saveSensorData(SensorData sensorData) {
        sensorRepository.save(sensorData);
    }

    public List<SensorData> getAllSensorData() {
        return sensorRepository.findAll();
    }

    public Optional<SensorData> getRecentSensorData() {
        return sensorRepository.findLastData();
    }
}
