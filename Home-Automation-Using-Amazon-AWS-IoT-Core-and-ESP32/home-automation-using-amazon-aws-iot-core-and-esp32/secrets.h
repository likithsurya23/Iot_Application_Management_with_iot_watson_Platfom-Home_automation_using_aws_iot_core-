#include <pgmspace.h>
 
#define SECRET
#define THINGNAME "House_automation"                         //Thing Name
 
const char WIFI_SSID[] = "Liki_5G";               //WiFi Username
const char WIFI_PASSWORD[] = "7676044103";           //WiFi Password
const char AWS_IOT_ENDPOINT[] = "a3kt643sc3gc7w-ats.iot.eu-north-1.amazonaws.com";       //End Point Name
 
// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTE
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----

)EOF";
 
// Device Certificate                                               //change this
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAObNML5ajboIbinhnkodhe6SUuNzMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yNTAyMjAxNDAy
NDJaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCrw/FuNhrTN6i+AhUw
KxuRMfkiHG4HVpNbyu4vcyzVnmjMC4fxR/Cpo7+v2msmJzGsPLrrb3hZnyPkWtuz
79njPsbLypXfELveZ8M2y+n+Hf/HgvnImrHMDPs07LVqYhWBS3TqytTOx9jBu5EQ
dSw4rdtapfHVPIGiWToF/wRID1zTKvAKgnxo4l6Z3/mPDFXOF+6VOxAflqn8OdB2
t7c1iKK65iYZknQusMf9V7ti+5UWaBN36p26G3TvoJyyb14LIW1PEe11D7bdoOyZ
BkgZFBQIsh8VyGiiuPjics+nIfq88gUzkulNDB+3s5o3A4Up2f2OuRjbByl+McqB
tfT/AgMBAAGjYDBeMB8GA1UdIwQYMBaAFF+D6DcC/9IS41xiU6q3BAT1ul4AMB0G
A1UdDgQWBBQfCV66FlmHRE+hfNgSdWVlntoHiTAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAAqpeiYT7qYCBHWejUc5QYJyf
5hyRPz387ow/JJROSb5N6L32fRqcemyzshfKsFr5aFmdTxn8NDnX1enYDbmdXVLC
F1gK1Iv2yFL+m405pbe914ScLnjYbjAmdisj4EnEQo2mMcZwkgrOB+rcBma0EcIp
JkwGjmOS8Qd38XzXwaLC27+f/O69Rij5A5bBfzBnIevXX4USnoCqnw1Qh0RtBhB6
YQFVYCuLO7EA9y/zfi1G8vc1aXWFJSKMAqNUpu5LP6TIDpV0tVIxTUM75HEaF+Tm
9wHd+ZtZ7onyY2QOYALpSeiPslU+5VNUb4yqZlvqfzCXPgbiNkEU41yiAuLffg==
-----END CERTIFICATE-----
 
 
)KEY";
 
// Device Private Key                                               //change this
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEAq8PxbjYa0zeovgIVMCsbkTH5IhxuB1aTW8ruL3Ms1Z5ozAuH
8UfwqaO/r9prJicxrDy66294WZ8j5Frbs+/Z4z7Gy8qV3xC73mfDNsvp/h3/x4L5
yJqxzAz7NOy1amIVgUt06srUzsfYwbuREHUsOK3bWqXx1TyBolk6Bf8ESA9c0yrw
CoJ8aOJemd/5jwxVzhfulTsQH5ap/DnQdre3NYiiuuYmGZJ0LrDH/Ve7YvuVFmgT
d+qduht076Ccsm9eCyFtTxHtdQ+23aDsmQZIGRQUCLIfFchoorj44nLPpyH6vPIF
M5LpTQwft7OaNwOFKdn9jrkY2wcpfjHKgbX0/wIDAQABAoIBAQCemG1ztcFPBTVp
O8MUlrj9d4bxWA6/99BYESeb6FydYYah4IPE5QfxmqCDXslQkR/sSKbOfD5Dgg1B
7CKwIeatTGmCAawgKvNMh8JX9jA30rs5HFZGQ4+nONU6KNXZRHdWyrVJlb6orx4U
w3tOFuKd8ul26YJBwXxwyrIoly782K82fTi/tbhiz9IUkmcHqq1TxnHMHb+fe3IT
X1vsfwZNozvzgD1tpsSGIHIiWoyYaaqjybITvYJUeA4yYTolPLK7p+hMmldvcpo3
hyBxdaJbKQvM/8OFHeG8it2BZWCDSvzzQ4v8pUxhPyoYN4pD5+5FjBwaggwZQPQF
CW+JK1ABAoGBANSMNygJCj5bY+w19Lf6IFJ7OyaqNiDA2sB37VGC7fzJ0v1FFHfe
YUouEEBzyoKv65fAYD5bptxIscvF7K+fQBqWsulHFUicHIdToKiBeHrW51naLqlY
ooKwN9Ul96FP2F51cKw5woX5/KM4Uu3lAn3zXPJVSNV3v1lR0BumJ7pBAoGBAM7h
XbfF+j0i+/1FCKbeoMoQttn67Zmv+1SJxorQvxbUllVbB8KdUsvcMHgXpR7DFAm7
4mAnkgvTLfKhCoPb2oz/WjE6eMTBWgg8jx+0576RDUpEIAXCsU8GN2I6pDFIWOg7
3FMnXQH1vHOZXQHmB9sFxq67rhpjXFWhfpEhkV8/AoGAcsGhpgP7e99r+8TF8+8g
NGhEb4PG5bg6Y2BcyX2fcLSnLgd2HaH7dUmZjLL3y8efs7cyP3jMhnLZS+P4/nlE
6xYiUsEGRMXEwWvteg0tN2WAU4rxVo18cIMkIfj10iqB774Ir3QgCqYGOTnXzImw
5r/WlyBkypx0u4zoh4UWPgECgYAjZv+Rpkh3U9hJdBnR7IEZcxjHXqBwT2Q0CEu4
j5ZTwtdjDevbCu8TQb/tnSY9iGaSb9uCVuMwMNhJD/PrsqDIxh3aFMZ77RaKGErp
wxxxSQM8NUJBmhqbilXJ8n0MjfPg8fV3KWJKJpI0OgdnfsTTXz6rwiQ+EcjIQpWV
ImhtIwKBgQDJz3cNUHU3+csa2kD8N20jmavL/pe7H5ejb0yZcvTbdzVbYpJ3YzW0
6X0JI4+AktzbpH7NNJ0SYDTtFGc6GGuA7i94IlRlAIldMBIy8+xzZPl7PMhBIMsq
TFBW7YGedsc66EvI/69NLTB9s8Ouaqt7QC1oiidqCEK5gWQXe0ZHgg==
-----END RSA PRIVATE KEY-----

 
)KEY";
