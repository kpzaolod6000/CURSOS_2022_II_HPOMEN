from oscrypto import tls
from certvalidator import CertificateValidator, errors

session = tls.TLSSession(manual_validation=True)
connection = tls.TLSSocket('www.google.com', 443, session=session)

try:
    validator = CertificateValidator(connection.certificate, connection.intermediates)
    result = validator.validate_tls(connection.hostname)
    print(result)
    print(type(result))
    print(result.__module__)

except (errors.PathValidationError):
    print("error: ", errors)
    # The certificate did not match the hostname, or could not be otherwise validated

