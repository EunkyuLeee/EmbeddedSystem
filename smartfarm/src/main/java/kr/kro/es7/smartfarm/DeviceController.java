package kr.kro.es7.smartfarm;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class DeviceController {

    @Autowired
    private DeviceService deviceService;

    @GetMapping("/setLight")
    public String setLight(@RequestParam("value") String value) {
        return deviceService.setLight(value);
    }

    @GetMapping("/setWindow")
    public String setWindow(@RequestParam("value") String state) {
        return deviceService.setWindow(state);
    }

    @GetMapping("/getLight")
    public String getLight() {
        return deviceService.getLight().orElse(null);
    }

    @GetMapping("/getWindow")
    public String getWindow() {
        return deviceService.getWindow().orElse(null);
    }
}
