from django.db import models
from django.utils import timezone


class AccPlan(models.Model):
    account_id = models.CharField(max_length=1, primary_key=True)

    account_label = models.CharField(max_length=50)


class SegmentPlan(models.Model):
    segment_id = models.CharField(max_length=1, primary_key=True)

    related_account = models.ForeignKey(AccPlan, on_delete=models.PROTECT)

    segment_label = models.CharField(max_length=50)


class NichePlan(models.Model):
    niche_id = models.CharField(max_length=1, primary_key=True)

    related_segment = models.ForeignKey(SegmentPlan, on_delete=models.PROTECT)

    niche_label = models.CharField(max_length=50)


class Fact(models.Model):
    FLOW_DIRECTION_CHOICES = {"C": "Crédito", "D": "Débito"}

    accplan_id = models.ForeignKey(AccPlan, on_delete=models.PROTECT)

    history = models.TextField()

    description = models.CharField(max_length=45)

    value = models.DecimalField(max_digits=12, decimal_places=2)

    flow_direction = models.CharField(choices=FLOW_DIRECTION_CHOICES)

    date = models.DateField(default=timezone.now)
