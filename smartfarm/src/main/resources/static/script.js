// 페이지 이동 함수
function navigateTo(page) {
    switch(page) {
        case 'intro':
            alert("소개 페이지로 이동합니다.");
            // 실제로는 window.location.href = 'intro.html'; 이런 식으로 사용 가능
            break;
        case 'control':
            alert("제어 페이지로 이동합니다.");
            break;
        case 'monitor':
            alert("모니터링 페이지로 이동합니다.");
            break;
        default:
            alert("잘못된 페이지입니다.");
    }
}