var request = require('request');
var fs      = require('fs');
var path    = require('path');
var pemFile = path.resolve(__dirname, 'ssl/cert.pem');

var options = {
    url        : 'https://www.aidap.naimes.faa.gov/aidap/XmlNotamServlet',
    passphrase : 'password',
    ca         : fs.readFileSync(pemFile) //reading the pem file
};

request.get(options, function (error, response, body) {
    if (!error && response.statusCode === 200) {
        console.log(body); // Show the HTML for the website
    }
});