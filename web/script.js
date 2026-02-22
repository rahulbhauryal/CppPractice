// Simulated embedded device state
const state = {
    connected: false,
    cpu: 0,
    mem: 0,
    temp: 0,
    pollInterval: null,
};

// ── DOM helpers ────────────────────────────────────────────────────

function log(message, level = 'info') {
    const container = document.getElementById('logContainer');
    const entry = document.createElement('p');
    entry.className = `log-entry log-${level}`;
    const now = new Date();
    const ts = now.toTimeString().slice(0, 8);
    const tag = level.toUpperCase().padEnd(5);
    entry.textContent = `[${ts}] [${tag}] ${message}`;
    container.appendChild(entry);
    container.scrollTop = container.scrollHeight;
}

function setBar(barId, valueId, pct, unit = '%') {
    document.getElementById(barId).style.width = `${pct}%`;
    document.getElementById(valueId).textContent = `${pct}${unit}`;
}

// ── Connection ─────────────────────────────────────────────────────

function toggleConnection() {
    if (state.connected) {
        disconnect();
    } else {
        connect();
    }
}

function connect() {
    log('Attempting to connect to device…', 'info');

    // Simulate an async handshake
    setTimeout(() => {
        state.connected = true;
        updateConnectionUI();
        log('Device connected.', 'ok');
        startPolling();
    }, 800);
}

function disconnect() {
    state.connected = false;
    stopPolling();
    updateConnectionUI();
    setBar('cpuBar', 'cpuValue', 0);
    setBar('memBar', 'memValue', 0);
    setBar('tempBar', 'tempValue', 0, '°C');
    document.getElementById('cpuValue').textContent = '—';
    document.getElementById('memValue').textContent = '—';
    document.getElementById('tempValue').textContent = '—';
    log('Device disconnected.', 'warn');
}

function updateConnectionUI() {
    const dot   = document.getElementById('statusDot');
    const label = document.getElementById('statusLabel');
    const btn   = document.getElementById('btnConnect');

    if (state.connected) {
        dot.classList.add('connected');
        label.textContent = 'Connected';
        btn.textContent   = 'Disconnect';
    } else {
        dot.classList.remove('connected');
        label.textContent = 'Disconnected';
        btn.textContent   = 'Connect';
    }
}

// ── Polling (simulated sensor data) ───────────────────────────────

function startPolling() {
    if (state.pollInterval) return;
    state.pollInterval = setInterval(fetchStatus, 2000);
    fetchStatus(); // immediate first read
}

function stopPolling() {
    clearInterval(state.pollInterval);
    state.pollInterval = null;
}

function fetchStatus() {
    if (!state.connected) return;

    // Simulate realistic-looking sensor values drifting over time
    state.cpu  = clamp(state.cpu  + rand(-8, 8),   5, 95);
    state.mem  = clamp(state.mem  + rand(-4, 4),  30, 85);
    state.temp = clamp(state.temp + rand(-2, 2),  35, 80);

    setBar('cpuBar',  'cpuValue',  Math.round(state.cpu));
    setBar('memBar',  'memValue',  Math.round(state.mem));
    setBar('tempBar', 'tempValue', Math.round(state.temp), '°C');

    // Warn if temperature is high
    if (state.temp > 72 && state.temp <= 75) {
        log(`Temperature warning: ${Math.round(state.temp)}°C`, 'warn');
    } else if (state.temp > 75) {
        log(`High temperature alert: ${Math.round(state.temp)}°C`, 'error');
    }
}

// ── Controls ───────────────────────────────────────────────────────

document.getElementById('displayToggle').addEventListener('change', function () {
    log(`Display turned ${this.checked ? 'ON' : 'OFF'}.`, this.checked ? 'ok' : 'warn');
});

document.getElementById('backlightToggle').addEventListener('change', function () {
    log(`Backlight turned ${this.checked ? 'ON' : 'OFF'}.`, this.checked ? 'ok' : 'warn');
});

document.getElementById('debugToggle').addEventListener('change', function () {
    log(`Debug mode ${this.checked ? 'enabled' : 'disabled'}.`, 'info');
});

document.getElementById('brightnessRange').addEventListener('input', function () {
    document.getElementById('brightnessValue').textContent = `${this.value}%`;
});

document.getElementById('brightnessRange').addEventListener('change', function () {
    log(`Brightness set to ${this.value}%.`, 'info');
});

function refreshStatus() {
    if (!state.connected) {
        log('Not connected — cannot refresh.', 'warn');
        return;
    }
    log('Refreshing status…', 'info');
    fetchStatus();
}

function resetDevice() {
    if (!state.connected) {
        log('Not connected — cannot reset.', 'warn');
        return;
    }
    log('Sending reset command to device…', 'warn');
    stopPolling();
    state.cpu  = 0;
    state.mem  = 0;
    state.temp = 0;
    setTimeout(() => {
        log('Device reset complete.', 'ok');
        startPolling();
    }, 1500);
}

function clearLog() {
    const container = document.getElementById('logContainer');
    container.innerHTML = '';
    log('Log cleared.', 'info');
}

// ── Utilities ─────────────────────────────────────────────────────

function rand(min, max) {
    return Math.random() * (max - min) + min;
}

function clamp(value, min, max) {
    return Math.min(Math.max(value, min), max);
}

// ── Init ───────────────────────────────────────────────────────────

(function init() {
    // Seed initial simulated values so the bars are non-zero after connect
    state.cpu  = 42;
    state.mem  = 58;
    state.temp = 47;
    log('Dashboard ready. Click "Connect" to start.', 'info');
})();
