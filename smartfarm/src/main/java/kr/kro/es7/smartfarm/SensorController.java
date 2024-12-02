package kr.kro.es7.smartfarm;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;
import java.util.Optional;

@RestController
public class SensorController {

    @Autowired
    private SensorService sensorService;

    @PostMapping("/addData")
    public String addSensorData(@RequestBody SensorData sensorData) {
        sensorService.saveSensorData(sensorData);
        return "success";
    }

    @GetMapping("/getAllData")
    public List<SensorData> getAllSensorData() {
        return sensorService.getAllSensorData();
    }

    @GetMapping("/getRecentData")
    public SensorData getRecentSensorData() {
        Optional<SensorData> data = sensorService.getRecentSensorData();
        return data.orElse(null);
    }
}
