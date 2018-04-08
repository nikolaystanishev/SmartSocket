from django.conf.urls import url

from WiFi_controll.views import WiFi_controll

urlpatterns = [
    url(r'', WiFi_controll),
]
