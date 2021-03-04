const express = require('express');
const restful = require('node-restful');
const bodyParser = require('body-parser')
const cors = require('cors');
const server = express();
const mongoose = restful.mongoose;

// Database
mongoose.Promise = global.Promise; // mongoose use Node Promise Api, because mongoose Promise is deprecated
mongoose.connect('mongodb://db/mydb');

// Middleware
server.use(bodyParser.urlencoded({ extended: true }));
server.use(bodyParser.json());
server.use(cors());

// ODM
const Client = restful.model('Client', {
    name: {type: String, require: true}
});

// Rest API
Client.methods(['get', 'post', 'put', 'delete']);
Client.updateOptions({new: true, runValidators: true});

// Routes
Client.register(server, '/clients')

// Start Server
server.listen(3000);