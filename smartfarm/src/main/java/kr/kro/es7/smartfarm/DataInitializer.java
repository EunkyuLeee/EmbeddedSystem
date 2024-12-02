package kr.kro.es7.smartfarm;

import jakarta.annotation.PostConstruct;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
public class DataInitializer {
    private final LightRepository lightRepository;
    private final WindowRepository windowRepository;

    @Autowired
    public DataInitializer(LightRepository lightDataRepository, WindowRepository windowRepository) {
        this.lightRepository = lightDataRepository;
        this.windowRepository = windowRepository;
    }

    @PostConstruct
    public void init() {
        // 초기 데이터 삽입
        LightData initialData = new LightData(null, "0%");
        lightRepository.save(initialData);
        WindowData initialWindowData = new WindowData(null, "닫힘");
        windowRepository.save(initialWindowData);
    }
}
