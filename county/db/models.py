from django.db import models
from django.utils import timezone


class tab_accPlan(models.Model):
    
    account_id = models.CharField(max_length=1)
    account_label = models.CharField(max_length=50)
    
    segment_id = models.CharField(max_length=1)
    segment_label = models.CharField(max_length=50)
    
    niche_id = models.CharField(max_length=1)
    niche_label = models.CharField(max_length=50)


class tab_fact(models.Model):
    
    FLOW_DIRECTION_CHOICES = {
        "C": "Crédito",
        "D": "Débito"
    }
    
    accPlan_id = models.ForeignKey(tab_accPlan, on_delete=models.PROTECT)
    
    history = models.TextField()
    
    description = models.CharField(max_length=45)
    
    value = models.DecimalField(max_digits=12, decimal_places=2)
    
    flow_direction = models.CharField(choices=FLOW_DIRECTION_CHOICES)
    
    date = models.DateField(default=timezone.now)
    
    relation = models.ManyToManyField("self", symmetrical=True)
