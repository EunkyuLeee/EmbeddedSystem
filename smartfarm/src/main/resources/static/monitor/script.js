document.addEventListener('DOMContentLoaded', () => {
    fetch('/getRecentData')
        .then(response => response.json())
        .then(data => {
            document.getElementById('temperature').textContent = `${data.temperature}°C`;
            document.getElementById('humidity').textContent = `${data.humidity}%`;
            document.getElementById('brightness').textContent = `${data.brightness}%`;
            document.getElementById('co2').textContent = `${data.co2}`;
            document.getElementById('soilMoisture').textContent = `${data.soil_moisture}%`;
            document.getElementById('intrusionDetection').textContent = data.intrusion;
        });
});

document.addEventListener('DOMContentLoaded', () => {
    fetch('/getLight')
        .then(response => response.text())
        .then(data => {
            document.getElementById('lightStatus').textContent = data;
            document.getElementById('brightness-slider').value = parseInt(data);
        });
    fetch('/getWindow')
        .then(response => response.text())
        .then(data => {
            document.getElementById('windowStatus').textContent = data;
        });
});

document.addEventListener('DOMContentLoaded', () => {

    const brightnessSlider = document.getElementById('brightness-slider');
    const brightnessValue = document.getElementById('lightStatus');

    brightnessSlider.addEventListener('input', () => {
        brightnessValue.textContent = `${brightnessSlider.value}%`;
        fetch("/setLight?value=" + encodeURI(brightnessValue.textContent));
    });
});

function toggleWindow() {
    const windowStatus = document.getElementById('windowStatus');
    if (windowStatus.textContent === '열림') {
        windowStatus.textContent = '닫힘';
        fetch("/setWindow?value=" + "닫힘");
    } else {
        windowStatus.textContent = '열림';
        fetch("/setWindow?value=" + "열림");
    }
}