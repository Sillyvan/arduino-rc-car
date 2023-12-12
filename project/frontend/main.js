class ArduinoCommunication {
  constructor() {
    // this.socket = new WebSocket("ws://172.20.10.2:80");
    // setCallbacks();
  }

  httpGet(url) {
    fetch(url, {
      method: 'GET',
    });
  }

  interval;

  holdDown(direction) {
    console.log(direction);
    this.httpGet(`http://10.0.0.25/100/${direction}`);
  }

  reset() {
    this.httpGet(`http://10.0.0.25/100/stop`);
  }

  // setCallbacks() {
  //     this.socket.onmessage = (e) => {
  //         console.log("message", e);
  //         var data = JSON.parse(e.data);
  //         var message = data['message'];
  //         var type = data['type'];

  //         // switch case for what our message is we handle it differently :)
  //         switch (type) {
  //             case "video_stream":
  //                 break;
  //         }
  //     }

  //     this.socket.onopen = (e) => {
  //         console.log("open", e)
  //     }

  //     this.socket.onerror = (e) => {
  //         console.log("error", e)
  //     }

  //     this.socket.onclose = (e) => {
  //         console.log("close", e)
  //     }
  // }
}

let arduinoComs = new ArduinoCommunication();
