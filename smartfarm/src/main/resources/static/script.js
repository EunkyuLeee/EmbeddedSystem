// 페이지 이동 함수
function navigateTo(page) {
    switch(page) {
        case 'intro':
            alert("소개 페이지로 이동합니다.");
            window.location.href = 'intro/intro.html';
            break;
        case 'monitor':
            alert("모니터링/제어 페이지로 이동합니다.");
            window.location.href = 'monitor/monitor.html';
            break;
        default:
            alert("잘못된 페이지입니다.");
    }
}