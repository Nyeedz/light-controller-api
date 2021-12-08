const express = require('express');
const app = express();
const cors = require('cors');
const { Control } = require('magic-home');
const { Discovery } = require('magic-home');

app.use(cors());

app.get('/toggleLight', function (req, res) {
  let light = new Control(req.query.ip);
  setTimeout(() => {
    light.setPower(req.query.on === 'true').then((success) => {
      res.send(200);
    });
  }, 500);
});

app.get('/discover', function (req, res) {
  let discovery = new Discovery();
  discovery.scan(500).then((devices) => {
    const parseDevices = devices.map((device) => {
      console.log(device);
      return {
        ...device,
        place: device.address.includes('.15.19') ? 'sala' : 'bar',
      };
    });
    res.send({
      devices: parseDevices,
    });
  });
});

app.listen(3000, (err, suc) => {
  console.log('conectado');
});
