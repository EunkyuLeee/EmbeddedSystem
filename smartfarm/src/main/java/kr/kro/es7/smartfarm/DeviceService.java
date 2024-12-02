package kr.kro.es7.smartfarm;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Optional;

@Service
public class DeviceService {
    @Autowired
    private LightRepository lightRepository;

    @Autowired
    private WindowRepository windowRepository;

    public String setLight(String value) {
        LightData lightData = new LightData();
        lightData.setLight_value(value);
        lightRepository.save(lightData);
        return "success";
    }

    public String setWindow(String value) {
        WindowData windowData = new WindowData();
        windowData.setWindow_value(value);
        windowRepository.save(windowData);
        return "success";
    }

    public Optional<String> getLight() {
        return lightRepository.findLastData();
    }

    public Optional<String> getWindow() {
        return windowRepository.findLastData();
    }
}
