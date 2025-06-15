import smtplib
from email import encoders
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart

server = smtplib.SMTP('smtp.gmail.com', 587)

server.connect('smtp.gmail.com', 587)

server.ehlo() 
server.starttls()
server.ehlo()

with open('password.txt', 'r') as f:
  email = f.readline()
  password = f.readline()

server.login(email, password)

msg = MIMEMultipart()

# add header
msg['From'] = 'Walter White'
msg['To'] = 'rkrishinba@gmail.com'
msg['Subject'] = 'Dee'

# add text
with open('Python_Network_Programming/MailingClient/password.txt', 'r') as f:
  message = f.read()
msg.attach(MIMEText(message, 'plain'))

# add image
filename = 'Python_Network_Programming/MailingClient/walter.jpg'
attachment = open(filename, 'rb')

p = MIMEBase('application', 'octet-stream ')
p.set_payload(attachment.read())

encoders.encode_base64(p)
p.add_header('Content-Disposition', f'attachment; filename={filename}')

msg.attach(p)

text = msg.as_string()
server.sendmail('purpledragon4477@gmail.com', 'rkrishinba@gmail.com', text)